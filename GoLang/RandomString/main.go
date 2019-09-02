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
	strCount := int64(0)
	strMap := make(map[string]int64)
	str := ""
	if len(os.Args) == 3 {
		strLen, _ = strconv.ParseInt(os.Args[1], 10, 64)
		numStrings, _ = strconv.ParseInt(os.Args[2], 10, 64)
	}

	for numStrings > 0 {
		numStrings = numStrings - 1
		strCount = strCount + 1
		//sleep()
		str = GetRandString(strLen)
		_, found := strMap[str]
		if found {
			break
		} else {
			strMap[str] = strCount
		}
	}

	for key, _ := range strMap {
		log.Println(key)
	}

	if numStrings != 0 {
		log.Println("After generating ", strCount, " unique strings, String = ", str, " is repeated :(")
		log.Println(str, " is the ", strMap[str], "th string that I generated")
	} else {
		log.Println("All strings are unique :)")
	}
}
