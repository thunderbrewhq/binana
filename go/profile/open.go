package profile

import (
	"fmt"
	"io/fs"
	"os"
	"path/filepath"

	"github.com/thunderbrewhq/binana/go/symbols"
)

type Profile struct {
	loaded             bool
	Info               Info
	Directory          string
	ArtifactsDirectory string
	Symbols            symbols.Table
}

func (profile *Profile) Open(profile_directory, artifacts_directory string) (err error) {
	var dir fs.FileInfo
	dir, err = os.Stat(profile_directory)
	if err != nil {
		return
	}

	if !dir.IsDir() {
		err = fmt.Errorf("profile: game profile is not a directory")
		return
	}

	fmt.Println("opening profile", profile_directory)

	profile.Symbols.Init()
	profile.Directory = profile_directory
	profile.ArtifactsDirectory = artifacts_directory

	// read profile meta info
	if err = read_info(filepath.Join(profile_directory, "info.json"), &profile.Info); err != nil {
		return
	}

	// read symbols directory
	if err = profile.Symbols.Load(filepath.Join(profile_directory, "symbol")); err != nil {
		return
	}

	profile.loaded = true

	return
}
