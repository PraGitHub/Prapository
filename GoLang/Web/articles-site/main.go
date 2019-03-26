package main

import (
	"github.com/gin-gonic/gin"
)

var router *gin.Engine

func render(c *gin.Context, statusCode int, data gin.H, templateName string) {
	acceptValue := c.Request.Header.Get("Accept") // acceptValue is the value which tells whether the requested data type is json/xml/html/whatever
	switch acceptValue {
	case "application/json":
		// Respond with JSON
		c.JSON(statusCode, data["payload"])
	case "application/xml":
		// Respond with XML
		c.XML(statusCode, data["payload"])
	default:
		// Respond with HTML
		c.HTML(statusCode, templateName, data)
	}
}

func main() {
	router = gin.Default()
	router.LoadHTMLGlob("templates/*")
	gin.SetMode(gin.ReleaseMode)
	initializeRoutes()
	router.Run()
}
