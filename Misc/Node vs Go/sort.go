package main

import (
	"fmt"
	"io/ioutil"
	"strings"
	"time"
	"strconv"
)

func readFile(filePath string) (array []int64) {
	inputFile, _ := ioutil.ReadFile(filePath)
	inputFileStr := string(inputFile)
	lines := strings.Split(inputFileStr, "\r\n")
	for i, _ := range lines {
		numbers := strings.Split(lines[i]," ")
		for j,_:=range numbers{
			number,_ := strconv.ParseInt(numbers[j],10,64)
			array = append(array,number)
		}
	}
	return
}
/*
func readFile(filePath string) (numbers []int) {
	fd, err := os.Open(filePath)
	if err != nil {
		//panic(fmt.Sprintf("open %s: %v", filePath, err))
	}
	var line int
	for {

		_, err := fmt.Fscanf(fd, "%d", &line)
		fmt.Println("line = ", line)
		if err != nil {
			//fmt.Println(err)
			if err == io.EOF {
				return
			}
			//panic(fmt.Sprintf("Scan Failed %s: %v", filePath, err))

		}
		numbers = append(numbers, line)
	}
	return
}
*/
func bubbleSort(x []int64) []int64 {

	end := len(x) - 1

	for {

		if end == 0 {
			break
		}

		for i := 0; i < len(x)-1; i++ {

			if x[i] > x[i+1] {
				x[i], x[i+1] = x[i+1], x[i]
			}

		}

		end -= 1

	}
	return x
}

func main() {
	array := readFile("input")
	//fmt.Println(array)
	fmt.Println("n = ", len(array))
	fmt.Println("main :: before calling bubbleSort", time.Now())
	array = bubbleSort(array)
	fmt.Println("main :: after calling bubbleSort", time.Now())
	//fmt.Println(array)
	var strOutput string
	strOutput = ""
	for i, _ := range array {
		strOutput = strOutput + strconv.FormatInt(int64(i),16) + " "
	}
	ioutil.WriteFile("gooutput", []byte(strOutput), 0644)
}
