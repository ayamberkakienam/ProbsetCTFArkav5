package service

import (
	"database/sql"
	"errors"
	"fmt"
	"log"
	"strings"

	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe_loona/database"
	"github.com/ayamberkakienam/ProbsetCTFArkav5/web/fancafe_loona/entity"
)

type PostService struct {
	ErrNotFound error
}

func NewPostService() *PostService {
	return &PostService{
		ErrNotFound: errors.New("Post not found"),
	}
}

func (p *PostService) Get(id int64) (entity.Post, error) {
	query := fmt.Sprintf("SELECT * FROM posts WHERE id = %d", id)
	post := entity.Post{}
	err := database.MySQL.Get(&post, query)
	if err != nil {
		if err == sql.ErrNoRows {
			err = p.ErrNotFound
		}
		return entity.Post{}, err
	}
	return post, nil
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
	keyword = strings.Fields(filter(keyword))[0]

	query := fmt.Sprintf(
		"SELECT * FROM posts WHERE is_deleted = false AND title LIKE '%%%s%%' OR content LIKE '%%%s%%'",
		keyword, keyword,
	)
	log.Println(query)
	posts := []entity.Post{}
	err := database.MySQL.Select(&posts, query)
	if err != nil {
		return nil, err
	}
	return posts, nil
}

// Uhh our logs show that people abusing /**/ smh
// Let's prevent injection by escaping quotes too
var mapping = map[string]string{
	"/": " ",
	"*": " ",
	"'": "\\'",
	"\"": "\\\"",
}
func filter(input string) string {
	for k, v := range mapping {
		input = strings.Replace(input, k, v, -1)
	}
	return input
}
