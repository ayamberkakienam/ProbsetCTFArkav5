package handler

import (
	"log"
	"net/http"
)

var (
	Home *HomeHandler
)

func Init() {
	Home = NewHomeHandler()
}

func response(w http.ResponseWriter, err error, code int) {
	log.Println(err)
	http.Error(w, http.StatusText(code), code)
}

func responseError(w http.ResponseWriter, err error) {
	response(w, err, http.StatusInternalServerError)
}

func responseNotFound(w http.ResponseWriter, err error) {
	response(w, err, http.StatusNotFound)
}
