package main

import (
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

func initializeRoutes() {
	router.GET("/", homePage)
}
