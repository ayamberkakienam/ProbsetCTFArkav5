package service

import (
	"log"
	"strings"

	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe/database"
	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe/entity"
)

type PostService struct {
}

func NewPostService() *PostService {
	return &PostService{}
}

func (p *PostService) All() ([]entity.Post, error) {
	query := "SELECT * FROM posts WHERE is_deleted = false"
	posts := []entity.Post{}
	err := database.MySQL.Select(&posts, query)
	if err != nil {
		return nil, err
	}
	return posts, nil
}

func (p *PostService) Search(keyword string) ([]entity.Post, error) {
	// We only support one keyword at the moment
	keyword = strings.Fields(keyword)[0]
	query := "SELECT * FROM posts WHERE is_deleted = false AND content LIKE '%" + keyword + "%'"
	log.Println(query)
	posts := []entity.Post{}
	err := database.MySQL.Select(&posts, query)
	if err != nil {
		return nil, err
	}
	return posts, nil
}
