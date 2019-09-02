package main

import (
	"time"
)

var chars = "QWERTYUIOPASDFGHJKLZXCVBNM1234567890qwertyuiopasdfghjklzxcvbnm"
var magical_ten_chars = "ilrawjoagk"
var magical_five_chars = "sptde"

var MAX_SHIFT = int64(1000)
var shiftValue = int64(0)

func makePositive(num int64) int64 {
	if num < 0 {
		return -num
	}
	return num
}

// this is to mae sure if the function is called multiple times at the same nanosecond
// then the string that gets generated should unique
func shift() int64 {
	if shiftValue == MAX_SHIFT {
		shiftValue = 0
	} else {
		shiftValue = shiftValue + 1
	}
	return shiftValue
}

// pass length of string as argument
func GetRandString(slen int64) (str string) {
	str = ""
	start := time.Now().UnixNano()
	tenCharPos := start % 10
	sValue := shift()
	start = start * (int64(byte(magical_ten_chars[tenCharPos])) + sValue)
	end := start + slen - 1

	for i := start; i <= end; i++ {
		num := i * time.Now().UnixNano()
		num = makePositive(num)
		fiveCharPos := int64(-1)
		if num%7 == 0 {
			fiveCharPos = 0
		} else if num%5 == 0 {
			fiveCharPos = 1
		} else if num%3 == 0 {
			fiveCharPos = 2
		} else if num%2 == 0 {
			fiveCharPos = 3
		} else {
			fiveCharPos = 4
		}
		num = num * int64(byte(magical_five_chars[fiveCharPos]))
		num = makePositive(num)
		charPos := (num / (sValue + 1)) % 62
		str = str + string(chars[(charPos)])
	}
	return
}
