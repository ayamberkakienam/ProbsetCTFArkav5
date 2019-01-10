package main

import (
	"fmt"
	"log"
	"net/http"

	"github.com/subosito/gotenv"

	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe"
)

func init() {
	gotenv.Load()
}

func main() {
	app := fancafe.NewFancafe()
	log.Println("Fancafe will listen at port 31337")

	err := http.ListenAndServe(":31337", app.Router)
	if err != nil {
		panic(fmt.Sprintf("Failed to listen and serve: %s", err))
	}
}
