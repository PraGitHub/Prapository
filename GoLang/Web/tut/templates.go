package main

import(
	"net/http"
	"html/template"
)

type myStruct struct{
	Title string
	Names []string
}

func handler(w http.ResponseWriter, r *http.Request){
	tmpl := template.Must(template.ParseFiles("template.html"))
	data := myStruct{
		Title:"CRUD",
		Names:[]string{
			"Create",
			"Update",
			"Read",
			"Delete",
		},
	}
	tmpl.Execute(w,data)
}

func main(){
	http.HandleFunc("/",handler)
	http.ListenAndServe(":8080",nil)
}