package handler

import (
	"html/template"
	"math/rand"
	"net/http"

	"github.com/julienschmidt/httprouter"

	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe_loona/entity"
	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe_loona/service"
)

type HomeHandler struct {
	homeTemplate *template.Template
}

func NewHomeHandler() *HomeHandler {
	homeTemplate := template.Must(template.ParseFiles("view/home.html"))
	return &HomeHandler{homeTemplate}
}

type homeTemplateData struct {
	StickyPosts []entity.Post
	Posts       []entity.Post
}

func (h *HomeHandler) Index(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
	allPosts, err := service.Post.All()
	if err != nil {
		responseError(w, err)
		return
	}

	var posts, stickyPosts []entity.Post
	for _, post := range allPosts {
		if post.IsSticky {
			stickyPosts = append(stickyPosts, post)
		} else {
			posts = append(posts, post)
		}
	}

	rand.Shuffle(len(posts), func(i, j int) {
		posts[i], posts[j] = posts[j], posts[i]
	})
	h.homeTemplate.Execute(w, homeTemplateData{stickyPosts, posts})
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
	h.homeTemplate.Execute(w, homeTemplateData{nil, posts})
}
