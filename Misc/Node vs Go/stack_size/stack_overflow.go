package main

import(
	"os"
	"strconv"
)

var count int64 = 0

func stackOverflow(){
	count = count + 1
	if count%1000 == 0{
		file,_ := os.Create("./results/go/stackOverflow.go.result"+os.Args[1])
		defer file.Close()
		file.Write([]byte(strconv.FormatInt(count,10)))
		file.Sync()
	}
	stackOverflow()
}

func main(){
	stackOverflow()
}