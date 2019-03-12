package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"strconv"
)

func request(id int, ch chan string) {
	response, err := http.Get("http://localhost:8085")
	if err != nil {
		fmt.Println("goRoutineId = ", id, "err = ", err)
		os.Exit(1)
	} else {
		defer response.Body.Close()
		contents, err := ioutil.ReadAll(response.Body)
		if err != nil {
			fmt.Println("goRoutineId = ", id, "err = ", err)
			os.Exit(1)
		}
		ch <- "goRoutineId = " + strconv.Itoa(id) + " response = " + string(contents)
	}
}

func main() {
	count := 0
	numRequests, _ := strconv.ParseInt(os.Args[1], 10, 64)
	ch := make(chan string)
	fmt.Println("numRequests = ", numRequests)
	for {
		count++
		if int64(count) > numRequests {
			break
		}
		go request(count, ch)
	}
	count = 0
	for {
		count++
		if int64(count) > numRequests {
			break
		}
		fmt.Println(count, " :: response :: ", <-ch)
	}
	fmt.Println("value of count at the end of the test = ", count)
}
