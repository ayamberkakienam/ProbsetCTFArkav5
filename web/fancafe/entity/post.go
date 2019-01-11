package entity

type Post struct {
	ID        int64  `db:"id"`
	IsDeleted bool   `db:"is_deleted"`
	Title     string `db:"title"`
	Content   string `db:"content"`
}
