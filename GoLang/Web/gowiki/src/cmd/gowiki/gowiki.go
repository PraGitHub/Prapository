package main

import (
	"errors"
	"fmt"
	"html/template"
	"io/ioutil"
	"log"
	"net/http"
	"regexp"
	"strings"
)

type Page struct {
	Title string
	Body  []byte
}

var templates = template.Must(template.ParseFiles("../templates/edit.html", "../templates/view.html", "../templates/create.html"))
var validPath = regexp.MustCompile("^/(edit|save|view)/([a-zA-Z0-9]+)$")

/*
func getHTMLBody(body []byte)([]byte){
	str_body := string(body)
	str_body = strings.Replace(str_body,"\r\n","<br>",-1)
	str_body = strings.Replace(str_body,"\n","<br>",-1)
	return []byte(str_body)
}
*/

func (page *Page) save() error {
	filename := page.Title + ".txt"
	return ioutil.WriteFile("../data/"+filename, page.Body, 0600)
}

func loadPage(title string) (*Page, error) {
	filename := title + ".txt"
	body, err := ioutil.ReadFile("../data/" + filename)
	if err != nil {
		return nil, err
	}
	return &Page{Title: title, Body: body}, nil
}

/*
func loadPageForWeb(title string)(*Page,error){
	filename := title+".txt"
	body,err := ioutil.ReadFile("./data/"+filename)
	if err != nil{
		return nil,err
	}
	htmlBody := getHTMLBody(body)
	return &Page{Title:title,Body:htmlBody},nil
}
*/

func renderTemplate(w http.ResponseWriter, tmpl string, page *Page) {
	//page.Body
	safeBody := string(page.Body)
	log.Println("renderTemplate :: safe_body before = ", safeBody)
	safeBody = strings.Replace(safeBody, "\r\n", "<br>", -1)
	safeBody = strings.Replace(safeBody, "\n", "<br>", -1)
	safeBody = template.HTMLEscapeString(safeBody)
	log.Println("renderTemplate :: safe_body after = ", safeBody)
	page.Body = []byte(safeBody)
	err := templates.ExecuteTemplate(w, tmpl+".html", page)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
	}
}

func getTitle(w http.ResponseWriter, r *http.Request) (string, error) {
	m := validPath.FindStringSubmatch(r.URL.Path)
	log.Println("getTitle :: m = ", m, "m[0] = ", m[0], "m[1] = ", m[1], "m[2] = ", m[2])
	if m == nil {
		http.NotFound(w, r)
		return "", errors.New("Invalid Page Title")
	}
	return m[2], nil // The title is the second subexpression.
}

func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hi there, I love %s!", r.URL.Path[1:])
	//log.Println("handler :: r = ",r)
}

func viewHandler(w http.ResponseWriter, r *http.Request) {
	title, err := getTitle(w, r)
	if err != nil {
		return
	}
	page, err := loadPage(title)
	if err != nil {
		page = &Page{Title: title, Body: []byte(" Error : Requested page not found")}
		renderTemplate(w, "create", page)
	} else {
		renderTemplate(w, "view", page)
	}
}

func editHandler(w http.ResponseWriter, r *http.Request) {
	title, err := getTitle(w, r)
	if err != nil {
		return
	}
	page, err := loadPage(title)
	if err != nil {
		page = &Page{Title: title}
	}
	renderTemplate(w, "edit", page)
}

func saveHandler(w http.ResponseWriter, r *http.Request) {
	title, err := getTitle(w, r)
	if err != nil {
		return
	}
	body := r.FormValue("body")
	page := &Page{Title: title, Body: []byte(body)}
	err = page.save()
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}
	http.Redirect(w, r, "/view/"+title, http.StatusFound)
}

func main() {
	http.HandleFunc("/", handler)
	http.HandleFunc("/view/", viewHandler)
	http.HandleFunc("/edit/", editHandler)
	http.HandleFunc("/save/", saveHandler)
	log.Fatal(http.ListenAndServe(":8080", nil))
}
