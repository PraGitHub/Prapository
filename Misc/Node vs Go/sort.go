package main

import (
	"fmt"
	"io/ioutil"
	"strings"
	"time"
	"strconv"
	"math/rand"
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

func quickSort(a []int64) []int64 {
    if len(a) < 2 {
        return a
    }
      
    left, right := 0, len(a)-1
      
    pivot := rand.Int() % len(a)
      
    a[pivot], a[right] = a[right], a[pivot]
      
    for i, _ := range a {
        if a[i] < a[right] {
            a[left], a[i] = a[i], a[left]
            left++
        }
    }
      
    a[left], a[right] = a[right], a[left]
      
    quickSort(a[:left])
    quickSort(a[left+1:])
      
    return a
}

func main() {
	array := readFile("input")
	//fmt.Println(array)
	fmt.Println("n = ", len(array))

	fmt.Println("main :: before calling quickSort", time.Now())
	quickSortedArray := quickSort(array)
	fmt.Println("main :: after calling quickSort", time.Now())
	
	fmt.Println("main :: before calling bubbleSort", time.Now())
	bubbleSortedArray := bubbleSort(array)
	fmt.Println("main :: after calling bubbleSort", time.Now())

	var strOutput string

	strOutput = ""
	for i, _ := range quickSortedArray {
		strOutput = strOutput + strconv.FormatInt(int64(i),10) + " "
	}
	ioutil.WriteFile("gooutput_quicksort", []byte(strOutput), 0644)

	strOutput = ""
	for i, _ := range bubbleSortedArray {
		strOutput = strOutput + strconv.FormatInt(int64(i),10) + " "
	}
	ioutil.WriteFile("gooutput_bubblesort", []byte(strOutput), 0644)
}
