all: generate

ce-lua:
	./script/build-cheatengine-scripts cheatengine profile/3.3.5a-windows-386/cheatengine

artifacts:
	./bin/bna mk 3.3.5a-windows-386

generate: artifacts

tidy:
	./bin/bna tidy 3.3.5a-windows-386

dependencies:
	mkdir -p bin
	go build -o bin/bna github.com/thunderbrewhq/binana/go/cmd/bna
