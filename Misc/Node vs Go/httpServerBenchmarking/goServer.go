package main

import (
	"fmt"
	"log"
	"net/http"
)

var count int64 = 0

func handler(w http.ResponseWriter, r *http.Request) {
	count++
	fmt.Fprintf(w, "go server :: client no %d", count)
}

func main() {
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe(":8085", nil))
}
