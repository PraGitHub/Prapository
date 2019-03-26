package main

import (
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
)

func homePage(c *gin.Context) {
	c.HTML(
		http.StatusOK,
		"index.html",
		gin.H{
			"title":   "Articles",
			"payload": getAllArticles(),
		},
	)
}

func viewArticle(c *gin.Context) {
	id := c.Param("id")
	found, retArticle := getArticleById(id)
	statusCode := http.StatusNotFound
	if found {
		statusCode = http.StatusOK
	}

	log.Println("viewArticle :: retArticle = ", retArticle)

	c.HTML(
		statusCode,
		"view_article.html",
		gin.H{
			"title":   retArticle.Title,
			"found":   found,
			"payload": retArticle,
		},
	)
}

func initializeRoutes() {
	router.GET("/", homePage)
	router.GET("/article/view/:id", viewArticle)
}
