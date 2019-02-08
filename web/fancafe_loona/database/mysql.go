package database

import (
	"fmt"
	"os"
	"time"

	_ "github.com/go-sql-driver/mysql"
	"github.com/jmoiron/sqlx"
)

func NewMySQL() *sqlx.DB {
	username := os.Getenv("DATABASE_USERNAME")
	password := os.Getenv("DATABASE_PASSWORD")
	host := os.Getenv("DATABASE_HOST")
	port := os.Getenv("DATABASE_PORT")
	name := os.Getenv("DATABASE_NAME")

	dataSourceName := fmt.Sprintf("%s:%s@tcp(%s:%s)/%s?charset=utf8mb4,utf8", username, password, host, port, name)
	db := sqlx.MustConnect("mysql", dataSourceName)
	db.SetConnMaxLifetime(time.Minute)
	db.SetMaxIdleConns(0)
	db.SetMaxOpenConns(256)
	return db
}
