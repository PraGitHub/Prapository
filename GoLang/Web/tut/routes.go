package main

import (
	"fmt"
	"net/http"

	"github.com/gorilla/mux"
)

var sliceBooks []string

func CreateBook(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	for _, book := range sliceBooks {
		if book == vars["title"] {
			fmt.Fprint(w, book+" is already present")
			return
		}
	}
	sliceBooks = append(sliceBooks, vars["title"])
	fmt.Fprint(w, vars["title"]+" is Added")
}

func ReadBook(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	for _, book := range sliceBooks {
		if book == vars["title"] {
			fmt.Fprint(w, book+" is Found\nYou can read it")
			return
		}
	}
	fmt.Fprint(w, vars["title"]+" is not Found")
}

func UpdateBook(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	for _, book := range sliceBooks {
		if book == vars["title"] {
			fmt.Fprint(w, book+" is Found and Updated")
			return
		}
	}
	fmt.Fprint(w, vars["title"]+" is not Found")
}

func DeleteBook(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	for i, book := range sliceBooks {
		if book == vars["title"] {
			if len(sliceBooks) == 1 {
				sliceBooks = make([]string, 0)
				fmt.Fprint(w, book+" is Found and Deleted")
				return
			}
			if i == len(sliceBooks)-1 {
				sliceBooks = sliceBooks[0:i]
			} else if i == 0 {
				sliceBooks = sliceBooks[i+1:]
			} else {
				sliceBooks = append(sliceBooks[0:i], sliceBooks[i+1:]...)
			}
			fmt.Fprint(w, book+" is Found and Deleted")
			return
		}
	}
	fmt.Fprint(w, vars["title"]+" is not Found")
}

func main() {
	rout := mux.NewRouter()

	r := rout.PathPrefix("/elements/").Subrouter()

	r.HandleFunc("/books/{title}", CreateBook).Methods("POST")
	r.HandleFunc("/books/{title}", ReadBook).Methods("GET")
	r.HandleFunc("/books/{title}", UpdateBook).Methods("PUT")
	r.HandleFunc("/books/{title}", DeleteBook).Methods("DELETE")
	r.HandleFunc("/books/{title}/page/{page}", func(w http.ResponseWriter, r *http.Request) {
		vars := mux.Vars(r)
		title := vars["title"]
		page := vars["page"]

		fmt.Fprintf(w, "You've requested the book: %s on page %s\n", title, page)
	})

	http.ListenAndServe(":8080", r)
}
