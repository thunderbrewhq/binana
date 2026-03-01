package cmd

import (
	_ "github.com/thunderbrewhq/binana/go/app/cmd/add_symbol"
	_ "github.com/thunderbrewhq/binana/go/app/cmd/lint"
	_ "github.com/thunderbrewhq/binana/go/app/cmd/make"
	"github.com/thunderbrewhq/binana/go/app/cmd/root"
	_ "github.com/thunderbrewhq/binana/go/app/cmd/tidy"

	"github.com/thunderbrewhq/binana/go/app"
)

func Execute() {
	err := root.RootCmd.Execute()
	if err != nil {
		app.Fatal(err)
	}
}
