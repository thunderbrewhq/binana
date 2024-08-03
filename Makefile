all: generate

compile-symbols:
	./script/compile-symbols 3.3.5a

ida-gen:
	./bin/binana ida-gen --game 3.3.5a

x64dbg-gen:
	./bin/binana x64dbg-gen --game 3.3.5a --base-address=00400000 --module-name=wow.exe

generate: compile-symbols x64dbg-gen ida-gen

dependencies:
	mkdir -p bin
	go build -v -o bin/binana github.com/thunderbrewhq/binana/go/cmd/binana
