package handler

import (
	"html/template"
	"net/http"

	"github.com/julienschmidt/httprouter"

	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe/entity"
	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe/service"
)

type HomeHandler struct {
	homeTemplate *template.Template
}

func NewHomeHandler() *HomeHandler {
	homeTemplate := template.Must(template.ParseFiles("view/home.html"))
	return &HomeHandler{homeTemplate}
}

type homeTemplateData struct {
	Posts []entity.Post
}

func (h *HomeHandler) Index(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
	posts, err := service.Post.All()
	if err != nil {
		responseError(w, err)
		return
	}
	h.homeTemplate.Execute(w, homeTemplateData{posts})
}

func (h *HomeHandler) Search(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
	if err := r.ParseForm(); err != nil {
		responseError(w, err)
		return
	}
	keyword := r.FormValue("keyword")

	posts, err := service.Post.Search(keyword)
	if err != nil {
		responseError(w, err)
		return
	}
	h.homeTemplate.Execute(w, homeTemplateData{posts})
}
