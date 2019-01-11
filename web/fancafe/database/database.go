package database

import (
	"github.com/jmoiron/sqlx"
)

var (
	MySQL *sqlx.DB
)

func Init() {
	MySQL = NewMySQL()
}
