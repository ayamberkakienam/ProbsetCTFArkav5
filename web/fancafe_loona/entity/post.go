package entity

type Post struct {
	ID        int64  `db:"id"`
	IsDeleted bool   `db:"is_deleted"`
	IsSticky  bool   `db:"is_sticky"`
	Title     string `db:"title"`
	Content   string `db:"content"`
	Video     string `db:"video"`
	Image     string `db:"image"`
}
