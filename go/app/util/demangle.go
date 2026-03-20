package util

import (
	"bytes"
	"fmt"
	"os/exec"
	"strings"
)

var demangle_cache = make(map[string]string)

func demangle(str string) (demangled string, err error) {
	var ok bool
	if demangled, ok = demangle_cache[str]; ok {
		return
	}

	var output bytes.Buffer
	c := exec.Command("demumble", str)
	c.Stdout = &output
	c.Run()
	if output.Len() == 0 {
		err = fmt.Errorf("cannot demangle")
		return
	}
	demangled = output.String()
	demangled = strings.TrimSuffix(demangled, "\n")
	if str == demangled {
		err = fmt.Errorf("cannot demangle")
		return
	}
	demangle_cache[str] = demangled
	return
}

func looks_mangled(str string) bool {
	if strings.HasPrefix(str, ".") {
		return true
	} else if strings.HasPrefix(str, "?") {
		return true
	} else if strings.HasPrefix(str, "_Z") {
		return true
	} else if len(str) > 0 && str[0] >= '0' && str[0] <= '9' {
		return true
	} else if strings.ContainsAny(str, "0123456789") && !strings.Contains(str, " ") {
		return true
	}
	return false
}
