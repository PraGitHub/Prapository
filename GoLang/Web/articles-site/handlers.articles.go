package main

import (
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
)

func initArticleRoutes() {
	router.GET("/article/view/:id", viewArticle)
}

func viewArticle(c *gin.Context) {
	id := c.Param("id")
	found, retArticle := getArticleById(id)
	statusCode := http.StatusNotFound
	title := "Article not Found"
	if found {
		statusCode = http.StatusOK
		title = retArticle.Title
	}

	log.Println("viewArticle :: retArticle = ", retArticle)

	render(
		c,
		statusCode,
		gin.H{
			"title":   title,
			"found":   found,
			"payload": retArticle,
		},
		"view_article.html",
	)
}
