package main

import (
	"log"
	"os"
	"strconv"
	"time"
)

func sleep() {
	time.Sleep(time.Nanosecond)
}

func main() {
	log.SetFlags(log.Ltime | log.Lmicroseconds)
	strLen := int64(40)
	numStrings := int64(1000)
	if len(os.Args) == 3 {
		strLen, _ = strconv.ParseInt(os.Args[1], 10, 64)
		numStrings, _ = strconv.ParseInt(os.Args[2], 10, 64)
	}

	for numStrings > 0 {
		numStrings = numStrings - 1
		//sleep()
		log.Println(GetRandString(strLen))
	}
}
