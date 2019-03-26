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

func aboutPage(c *gin.Context) {
	render(
		c,
		http.StatusOK,
		gin.H{
			"title": "About Us",
		},
		"about.html",
	)
}

func initializeRoutes() {
	router.GET("/", homePage)
	router.GET("/about", aboutPage)
	initArticleRoutes()
	initUserRoutes()
}
