package fancafe_loona

import (
	"net/http"

	"github.com/julienschmidt/httprouter"

	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe_loona/database"
	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe_loona/handler"
	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe_loona/service"
)

type FancafeLoona struct {
	Router http.Handler
}

func NewFancafeLoona() *FancafeLoona {
	database.Init()
	handler.Init()
	service.Init()

	router := httprouter.New()
	router.GET("/", handler.Home.Index)
	router.POST("/", handler.Home.Search)
	router.GET("/posts/:id", handler.Post.View)

	return &FancafeLoona{router}
}
