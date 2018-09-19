package main

import (
	"crypto"
	_ "crypto/md5"
	_ "crypto/sha1"
	_ "crypto/sha256"
	_ "crypto/sha512"
	"fmt"
)

var flag = "g0_RE_h4rd"
var blockSize = 1

func main() {
	availableHash := make([]crypto.Hash, 0, 100)
	for i := 0; i < 100; i++ {
		cryptoHash := (crypto.Hash)(i)
		if cryptoHash.Available() {
			availableHash = append(availableHash, cryptoHash)
		}
	}

	for i := 0; i < len(flag); i += blockSize {
		s := flag[:i+blockSize]
		input := []byte(s)
		for _, h := range availableHash {
			hash := h.New()
			hash.Write(input)
			input = hash.Sum(nil)
		}
		resultHash := input
		for i := 0; i < 100; i++ {
			resultSHA := crypto.SHA512.New()
			resultSHA.Write(resultHash)
			resultHash = resultSHA.Sum(nil)
		}
		fmt.Printf("\t\"%x\",\n", resultHash)
	}
}
