package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
)

func request(id int) {
	response, err := http.Get("http://localhost:8085")
	if err != nil {
		fmt.Printf("%s", err)
		os.Exit(1)
	} else {
		defer response.Body.Close()
		contents, err := ioutil.ReadAll(response.Body)
		if err != nil {
			fmt.Println("goRoutineId = ", id, "err = ", err)
			os.Exit(1)
		}
		fmt.Println("goRoutineId = ", id, "response = ", string(contents))
	}
}

func main() {
	count := 0
	for {
		count++
		//fmt.Println("count = ", count)
		if count > 1000 {
			break
		}
		go request(count)
	}
	for {
	}
}
