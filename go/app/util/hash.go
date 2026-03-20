package util

import (
	"crypto/sha256"
	"encoding/hex"
	"os"
)

func hash_file(name string) (id string, err error) {
	var b []byte
	b, err = os.ReadFile(name)
	if err != nil {
		return
	}
	h := sha256.New()
	h.Write(b[:])
	id = hex.EncodeToString(h.Sum(nil))
	return
}
