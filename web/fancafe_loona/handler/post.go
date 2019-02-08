package handler

import (
	"fmt"
	"html/template"
	"net/http"
	"net/url"
	"strconv"

	"github.com/julienschmidt/httprouter"

	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe_loona/entity"
	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe_loona/service"
)

type PostHandler struct {
	postTemplate *template.Template
}

func NewPostHandler() *PostHandler {
	postTemplate := template.Must(template.ParseFiles("view/post.html"))
	return &PostHandler{postTemplate}
}

type postTemplateData struct {
	Post entity.Post
}

func (h *PostHandler) View(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
	id, err := strconv.ParseInt(p.ByName("id"), 10, 64)
	if err != nil {
		responseNotFound(w, err)
		return
	}

	post, err := service.Post.Get(id)
	if err != nil {
		if err == service.Post.ErrNotFound {
			responseNotFound(w, err)
		} else {
			responseError(w, err)
		}
		return
	}

	u, err := url.Parse(post.Video)
	if err != nil {
		responseError(w, err)
		return
	}
	post.Video = fmt.Sprintf("https://youtube.com/embed/%s?rel=0", u.Query().Get("v"))

	h.postTemplate.Execute(w, postTemplateData{post})
}
