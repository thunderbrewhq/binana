all: generate

compile-symbols:
	./script/compile-symbols profile/3.3.5a-windows-386

profile-gen:
	./bin/binana generate --profile profile/3.3.5a-windows-386

generate: compile-symbols profile-gen

dependencies:
	mkdir -p bin
	go build -v -o bin/binana github.com/thunderbrewhq/binana/go/cmd/binana
