package x64dbg

import (
	"io"

	"github.com/pierrec/lz4/v4"
)

type lz4_writecloser struct {
	w *lz4.Writer
}

func new_lz4_writecloser(w io.Writer) (l *lz4_writecloser, err error) {
	l = new(lz4_writecloser)
	l.w = lz4.NewWriter(w)
	if err = l.w.Apply(lz4.LegacyOption(true)); err != nil {
		return
	}

	return
}

func (l *lz4_writecloser) Write(b []byte) (n int, err error) {
	n, err = l.w.Write(b)
	return
}

func (l *lz4_writecloser) Close() (err error) {
	err = l.w.Close()
	return
}
