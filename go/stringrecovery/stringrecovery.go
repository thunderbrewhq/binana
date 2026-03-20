package stringrecovery

import (
	"debug/macho"
	"debug/pe"
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"os"
	"strings"
)

var (
	charset_english      = ` !"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_abcdefghijklmnopqrstuvwxyz{|}~` + "`"
	lookup_table_english [256]bool
)

type (
	Callback func(segment_name string, address uint64, token string)
)

func init() {
	for _, c := range charset_english {
		lookup_table_english[c] = true
	}
}

func recover_section(try_align bool, word_size uint64, minimum_length int, section_name string, virtual_address uint64, section_reader io.ReaderAt, callback Callback) (err error) {
	var (
		offset int64
	)

	var (
		current_token        strings.Builder
		current_token_offset int64
	)

	for {
		var b [1]byte
		if _, err = section_reader.ReadAt(b[:], offset); err != nil {
			if err == io.EOF {
				err = nil
				break
			}
		}
		if b[0] == 0 {
			// if current_token != "", this is a 0-terminator
			// emit the token
			if current_token.Len() > 0 {
				if current_token.Len() < minimum_length {
					current_token.Reset()
					offset++
					continue
				}

				align_offset := 0

				if try_align {
					for i := uint64(current_token_offset); (i % word_size) != 0; i++ {
						current_token_offset++
						align_offset++
					}
				}

				current_token_string := current_token.String()
				current_token_string = current_token_string[align_offset:]

				callback(section_name, virtual_address+uint64(current_token_offset), current_token_string)
				current_token.Reset()
			}
			offset++
			continue
		}
		if lookup_table_english[b[0]] {
			if current_token.Len() == 0 {
				current_token_offset = offset
			}
			current_token.WriteByte(b[0])
		} else {
			// discard everything leaing up to this
			current_token.Reset()
		}
		offset++
	}

	return
}

func recover_file_macho(word_size uint64, file *os.File, callback Callback) (err error) {
	var (
		macho_file *macho.File
	)
	macho_file, err = macho.NewFile(file)
	if err != nil {
		return
	}
	for _, section := range macho_file.Sections {
		fmt.Fprintln(os.Stderr, "recovering", section.Name)
		switch section.Name {
		case "__cstring":
			if err = recover_section(false, word_size, 1, section.Name, section.Addr, section, callback); err != nil {
				return
			}
		case "__const":
			if err = recover_section(false, word_size, 4, section.Name, section.Addr, section, callback); err != nil {
				return
			}
		}
	}
	return
}

func recover_file_pe(file *os.File, callback Callback) (err error) {
	var (
		pe_file *pe.File
	)
	pe_file, err = pe.NewFile(file)
	if err != nil {
		return
	}
	image_base := uint64(0x400000)
	var word_size uint64

	switch h := pe_file.OptionalHeader.(type) {
	case *pe.OptionalHeader32:
		word_size = 4
		image_base = uint64(h.ImageBase)
	case *pe.OptionalHeader64:
		word_size = 8
		image_base = h.ImageBase
	}

	for _, section := range pe_file.Sections {
		fmt.Fprintln(os.Stderr, "recovering", section.Name)
		switch section.Name {
		case ".data":
			if err = recover_section(true, word_size, 4, section.Name, image_base+uint64(section.VirtualAddress), section, callback); err != nil {
				return
			}
		case ".rdata":
			if err = recover_section(true, word_size, 4, section.Name, image_base+uint64(section.VirtualAddress), section, callback); err != nil {
				return
			}
		}
	}

	return
}

func RecoverFile(filename string, callback Callback) (err error) {
	var file *os.File
	file, err = os.Open(filename)
	if err != nil {
		return
	}
	var magic [4]byte
	if _, err = file.ReadAt(magic[:], 0); err != nil {
		return
	}
	magic_number := binary.LittleEndian.Uint32(magic[:])
	if magic[0] == 'M' && magic[1] == 'Z' {
		err = recover_file_pe(file, callback)
	} else if magic_number == 0xfeedface {
		err = recover_file_macho(4, file, callback)
	} else if magic_number == 0xfeedfacf {
		err = recover_file_macho(8, file, callback)
	} else if magic_number == 0xcefaedfe {
		err = recover_file_macho(4, file, callback)
	} else {
		err = errors.New("unknown file magic: " + filename)
	}
	return
}
