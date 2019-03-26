package main

import (
	"github.com/gin-gonic/gin"
)

func viewSigninForm(c *gin.Context) {

}

func viewSignupForm(c *gin.Context) {

}

func signin(c *gin.Context) {

}

func signup(c *gin.Context) {

}

func signout(c *gin.Context) {

}

func initUserRoutes() {
	router.GET("/user/signin", viewSigninForm)
	router.GET("/user/signup", viewSignupForm)
	router.GET("/user/logout", signout)
	router.POST("/user/signin", signin)
	router.POST("/user/signup", signup)

}
