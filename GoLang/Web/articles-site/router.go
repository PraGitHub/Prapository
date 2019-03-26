package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func homePage(c *gin.Context) {
	render(
		c,
		http.StatusOK,
		gin.H{
			"title":   "Articles",
			"payload": getAllArticles(),
		},
		"index.html",
	)
}

func initializeRoutes() {
	router.GET("/", homePage)
	initArticleRoutes()
}
