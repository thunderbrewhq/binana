package db

type MirrorKind uint8

const (
	MirrorDirect MirrorKind = iota
	MirrorIPFS
)

type SampleMirror struct {
	Kind MirrorKind `json:"kind" parquet:"kind"`
	URL  string     `json:"url" parquet:"url,delta"`
}

type Sample struct {
	// The SHA-256 sum of the sample file
	ID string `json:"id" parquet:"id,dict"`

	// <Optional> if this is a debugging file, then this is a SHA-256 sum
	// which references another sample file, which is the executable file
	Executable string `json:"exe,omitempty" parquet:"exe,dict"`

	// This is the MIME type identifier of the sample file.
	// Possible sample types include:
	//  * (Windows .exe)  application/vnd.microsoft.portable-executable
	//  * (Mach-O binary) application/x-mach-binary
	//  * (Linux binary)  application/x-executable
	MimeType string `json:"mimetype" parquet:"mimetype,dict"`

	// This is the code that signifies which program the sample is a build of.
	Program string `json:"program" parquet:"program,dict"`

	// <Optional> This is the build sequence of the sample e.g. 12340
	Build uint32 `json:"build,omitempty" parquet:"build"`

	// <Optional> This is the semantic version/release id of the sample e.g. 3.3.5a
	Version string `json:"version,omitempty" parquet:"version"`

	// The OS of the sample, uses GOOS naming convention
	OS string `json:"os" parquet:"os,dict"`

	// The architecture of the sample, uses GOARCH naming convention
	Arch string `json:"arch" parquet:"arch,dict"`

	// A URL where the sample can be downloaded
	Mirrors []SampleMirror `json:"mirrors,omitempty" parquet:"mirrors"`
}
