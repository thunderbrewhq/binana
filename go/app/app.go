package app

import (
	"fmt"
	"os"
)

func Fatal(args ...any) {
	fmt.Fprintln(os.Stderr, args...)
	os.Exit(1)
}
