package service

var (
	Post *PostService
)

func Init() {
	Post = NewPostService()
}
