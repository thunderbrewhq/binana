package cmd

import (
	_ "github.com/thunderbrewhq/binana/go/app/cmd/lint"
	_ "github.com/thunderbrewhq/binana/go/app/cmd/make"
	_ "github.com/thunderbrewhq/binana/go/app/cmd/tidy"

	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/app/cmd/root"
)

func Execute() {
	err := root.RootCmd.Execute()
	if err != nil {
		app.Fatal(err)
	}
}
