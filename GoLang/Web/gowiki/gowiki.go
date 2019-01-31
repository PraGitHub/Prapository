package main 

import (
	"fmt"
	"log"
	"io/ioutil"
	"net/http"
)

type Page struct {
    Title string
    Body  []byte
}

func (page *Page) save() error {
    filename := page.Title + ".txt"
    return ioutil.WriteFile(filename, page.Body, 0600)
}

func loadPage(title string) (*Page,error) {
    filename := title + ".txt"
	body, err := ioutil.ReadFile(filename)
	if err != nil{
		return nil,err
	}
    return &Page{Title: title, Body: body},nil
}

func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hi there, I love %s!", r.URL.Path[1:])
	log.Println("handler :: r = ",r)
}

func viewHandler(w http.ResponseWriter, r *http.Request) {
    title := r.URL.Path[len("/view/"):]
	p, err := loadPage(title)
	if err!=nil{
		fmt.Fprintf(w,"<h1>Home</h1><div>This is Default page</div>")
	}else{
		fmt.Fprintf(w, "<h1>%s</h1><div>%s</div>", p.Title, p.Body)
	}
}

func main() {
	title := "TestPage"
    p1 := &Page{Title: "TestPage", Body: []byte("This is a sample Page.")}
    p1.save()
	p2, err := loadPage(title)
	if err != nil{
		fmt.Println("error while loading ",title, " : ")
		fmt.Println(err)
	}
	fmt.Println(string(p2.Body))
	
	http.HandleFunc("/", handler)
	http.HandleFunc("/view/",viewHandler)
    log.Fatal(http.ListenAndServe(":8080", nil))
}