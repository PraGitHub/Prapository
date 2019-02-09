package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprint(w, "Welcome to Static File Server")
	})

	staticFs := http.FileServer(http.Dir("static/"))

	http.Handle("/static/", http.StripPrefix("/static/", staticFs))

	http.ListenAndServe(":8080", nil)
}
