all: build

build:
	go build -buildmode=pie -ldflags="-w -extldflags=-Wl,-z,now,-z,relro" -gcflags="-N -l" -o nini-chan .