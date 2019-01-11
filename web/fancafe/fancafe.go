package fancafe

import (
	"net/http"

	"github.com/julienschmidt/httprouter"

	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe/database"
	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe/handler"
	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe/service"
)

type Fancafe struct {
	Router http.Handler
}

func NewFancafe() *Fancafe {
	database.Init()
	handler.Init()
	service.Init()

	router := httprouter.New()
	router.GET("/", handler.Home.Index)
	router.POST("/", handler.Home.Search)

	return &Fancafe{router}
}
