all: generate

compile-symbols:
	./script/compile-symbols profile/3.3.5a-windows

ida-gen:
	./bin/binana ida-gen --game profile/3.3.5a-windows

x64dbg-gen:
	./bin/binana x64dbg-gen --game profile/3.3.5a-windows --base-address=00400000 --module-name=wow.exe

generate: compile-symbols x64dbg-gen ida-gen

dependencies:
	mkdir -p bin
	go build -v -o bin/binana github.com/thunderbrewhq/binana/go/cmd/binana
