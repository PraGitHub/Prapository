package main

import (
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"time"
)

type pair struct {
	a, b int64
}

var max int64
var count int64
var sum int64
var arr []int64
var pairs []pair

func getRandNum() (n int64) {
	rand.Seed(time.Now().UnixNano())
	count++
	n = rand.Int63n(max) + count
	return
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

func usingHash() {
	hashTable := make(map[int64]int64, 0)
	first := true
	found := false
	var complement int64
	for _, num := range arr {
		if first {
			hashTable[num] = num
			first = false
			continue
		}

		complement = sum - num
		_, found = hashTable[complement]
		if found {
			pairs = append(pairs, pair{num, complement})
		}

		hashTable[num] = num
	}
}

func usingArr() {
	arr = quickSort(arr)
	//fmt.Println("arr after sort = ", arr)
	start := 0
	end := len(arr) - 1

	for true {
		if start >= end {
			break
		}
		if arr[start]+arr[end] < sum {
			start++
		} else if arr[start]+arr[end] > sum {
			end--
		} else {
			pairs = append(pairs, pair{arr[start], arr[end]})
			count++
			start++
			end--
		}
	}
}

func printLine() {
	fmt.Println("------------------------------------------------------------")
}

func main() {
	var i int64
	arr = make([]int64, 0)
	count = 0
	max, _ = strconv.ParseInt(os.Args[1], 10, 64)
	sum = getRandNum()

	for i = 0; i < max; i++ {
		arr = append(arr, getRandNum())
	}

	printLine()
	fmt.Println(time.Now(), " :: ", "num = ", max)
	printLine()
	fmt.Println(time.Now(), " :: ", "sum = ", sum)
	printLine()

	pairs = make([]pair, 0)
	printLine()
	fmt.Println(time.Now(), " :: ", "before usingHash")
	usingHash()
	fmt.Println(time.Now(), " :: ", "after usingHash")
	fmt.Println(time.Now(), " :: ", "usingHash returned ", len(pairs), " number of pairs")
	printLine()

	pairs = make([]pair, 0)
	printLine()
	fmt.Println(time.Now(), " :: ", "before usingArr")
	usingArr()
	fmt.Println(time.Now(), " :: ", "after usingArr")
	fmt.Println(time.Now(), " :: ", "usingHash returned ", len(pairs), " number of pairs")
	printLine()
}
