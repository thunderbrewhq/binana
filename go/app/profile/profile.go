package profile

import (
	"path/filepath"

	"github.com/thunderbrewhq/binana/go/app"
	"github.com/thunderbrewhq/binana/go/profile"
)

var Profile profile.Profile

func Open(profile_name string) {
	if profile_name == "" {
		app.Fatal("no profile selected")
	}
	if err := Profile.Open(
		filepath.Join("profile", profile_name),
		filepath.Join("artifacts", profile_name),
	); err != nil {
		app.Fatal(err)
	}
}

func Close() {
	//Profile.Close()
}
