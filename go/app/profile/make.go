package profile

import (
	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/profile"
)

type MakeParams struct {
	Profile string
	profile.CompileArtifactsParams
}

func Make(params *MakeParams) {
	Open(params.Profile)
	defer Close()

	if err := Profile.CompileArtifacts(&params.CompileArtifactsParams); err != nil {
		app.Fatal(err)
	}
}
