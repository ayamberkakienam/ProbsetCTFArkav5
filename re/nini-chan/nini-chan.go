package main

import (
	"crypto"
	_ "crypto/md5"
	_ "crypto/sha1"
	_ "crypto/sha256"
	_ "crypto/sha512"
	"flag"
	"fmt"
	"os"
	"sync"
)

var availableHash []crypto.Hash
var wg sync.WaitGroup
var inputChan chan string
var result []byte

var flagHash = []string{
	"633d38002c51397a6576185941ae3775b99690a88744c6f93df4df767794cd7f670c4946afa869e7b2aa57b767994c0e0bbe847240f7eae9356a9a87b6abb15a",
	"5f01969a9ecbeedf8ad1aa3df9d269eef87689601b802802eff12e1d92d3a23afa207d424a1f338fbdff8e6618f14da949eb154da8c01a151860cf4b4f4fa543",
	"a27f9e2c3d26f75eb7197dfc8f2f25fef9c68af0277477d8c1cab4a1c62111724202ea7df157b88a9321ee7a1e5030702f44c4e4ebfae6e4dcb4054c91a012e3",
	"5cc0b1128e30032bd6c8053ce1437eb162733e77bc4e17d287345f0d9d35bdaee040d7b12406d6cfebeacaa489460f55888e19b872aa1c568f0851c4106dd6ba",
	"73b1c6929c6c62edbe632dcf3d4ee57980576f63e18da39002dd7aa06680eb9c0607ed5acedeeeb186cb9c8cd123d03cf9d98ed0d1ef63a5c5cf00f3407e9f3a",
	"2070191c7acf8e6a81fd2a64aa32b33ffec40e7cd3343dfbb863cca53db7a40b95b4745a5b65d74314d597a5315c05630cf83f7f2ce2b9c06ee876c401cdc17a",
	"a40abb57ea60633c37664a7632cda31d7623c8dcd162ed0e34867366a9fb4356a0710f1fd0d13d76fb280b8a74538a48c1fdb83292a094af023bab23f4b99690",
	"ce7d2918e2551abfe060a867f53a2e33f71c65d062c63e314c51a4a5f592ad100c14cb1e183c22deffb1babf81051f63794b95dbb77dfbe9e17e776e16d1f5ac",
	"46cdb22e7fac2e6e3be3fb6f8134e3c61c5929c78d89335e3bbc283074f5af0a4a0f73fb408cbc8b412b9302cafa79be428a1f0b2fa69bf43d8c4a8dc4c288a5",
	"cd3f0b41847c71a5f4f45f603a38537921a8c3c9dee4c15e100f7e233b279a04de4fb56609566740870e1bc27674aa0db0ee0a261c42fd97dc113eb183cd34f8",
}

func init() {
	availableHash = make([]crypto.Hash, 0)
	for i := 0; i < 100; i++ {
		cryptoHash := (crypto.Hash)(i)
		if cryptoHash.Available() {
			availableHash = append(availableHash, cryptoHash)
		}
	}
	inputChan = make(chan string)
}

func main() {
	flag.Parse()

	if flag.NArg() != 1 {
		os.Exit(1)
	}

	input := flag.Arg(0)
	if len(input) != len(flagHash) {
		os.Exit(1)
	}

	for i := 0; i < len(input); i++ {
		wg.Add(1)
		go work()
		inputChan <- input[:i+1]
		wg.Wait()

		if inputHash() != flagHash[i] {
			os.Exit(1)
		}
	}

	fmt.Printf("Arkav5{%s}\n", input)
}

func work() {
	defer wg.Done()

	input := []byte(<-inputChan)
	for _, h := range availableHash {
		hash := h.New()
		hash.Write(input)
		input = hash.Sum(nil)
	}
	result = input
}

func inputHash() string {
	resultHash := result
	for i := 0; i < 100; i++ {
		resultSHA := crypto.SHA512.New()
		resultSHA.Write(resultHash)
		resultHash = resultSHA.Sum(nil)
	}
	return fmt.Sprintf("%x", resultHash)
}
