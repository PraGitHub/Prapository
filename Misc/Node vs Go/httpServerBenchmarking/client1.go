package main

import (
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"strconv"
	"time"
)

func request() {
	log.Printf("request :: begin | nano offset = %d", time.Now().Nanosecond())
	response, err := http.Get("http://localhost:8085")
	if err != nil {
		log.Fatalln("err in getting response = ", err)
	} else {
		defer response.Body.Close()
		contents, err := ioutil.ReadAll(response.Body)
		if err != nil {
			log.Fatalln("err in parsing response.Body = ", err)
		}
		log.Printf("request :: response = %s | nano offser = %d", string(contents), time.Now().Nanosecond())
	}
}

func main() {
	serverType := os.Args[1]
	fileCount := os.Args[2]
	numRequests, _ := strconv.ParseInt(os.Args[3], 10, 64)
	file, _ := os.Create("./response/" + serverType + "/result." + fileCount)
	log.SetFlags(log.Ldate | log.Ltime | log.Lmicroseconds)
	log.SetOutput(file)

	var i int64
	for i = 0; i < numRequests; i++ {
		request()
		time.Sleep(10 * time.Microsecond)
	}
}
