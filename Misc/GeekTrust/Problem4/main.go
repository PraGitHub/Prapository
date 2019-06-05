package main

import (
	"log"
	"os"
	"strconv"
)

type Batsman struct {
	dots, ones, twos, threes, fours, fives, sixes, out float64
}

var batsmenData = map[string]Batsman{}

func printLine() {
	log.Println("--------------------------------------------------------------------------------")
}

func parseIntFromString(s string) int64 {
	n, err := strconv.ParseInt(s, 10, 64)
	if err != nil {
		printLine()
		log.Println("prseIntFromString :: err = ", err)
		log.Println("Given input = ", s, " is not a number")
		printLine()
		log.Fatalln("Please try again with right inputs")
	}
	return n
}

func invalidOptions() {
	log.Println("Usage : ")
	log.Println("main.exe [input file path] [runs remaining] [overs remaining] [wickets in hand]")
	printLine()
	printLine()
	log.Println("Example : ")
	log.Println("main.exe input.file 40 4 3")
	printLine()
	log.Println("Here, 'input.file' contains comma separated values contaning batsmen and probabilities associated with different possibilities like below.")
	log.Println(`	name,dots,ones,twos,threes,fours,fives,sixes,out
			Kirat Boli,5,30,25,10,15,1,9,5
			N.S Nodhi,10,40,20,5,10,1,4,10
			R Rumrah,20,30,15,5,5,1,4,20
			Shshi Henra,30,25,5,0,5,1,4,30`)
	printLine()
	log.Println("40 is the number of runs remaining to  chase")
	printLine()
	log.Println("4 is the number of overs left")
	printLine()
	log.Println("3 is the number of wickets in hand")
	printLine()
	log.Fatalln("Please try again with right parameters")
}

func parseInput(inputFilePath string) {

}

func main() {
	if len(os.Args) != 5 {
		invalidOptions()
	}
	inputFilePath := os.Args[1]
	runs := parseIntFromString(os.Args[2])
	overs := parseIntFromString(os.Args[3])
	wickets := parseIntFromString(os.Args[4])

	printLine()
	log.Println("Given Inputs : ")
	log.Println("input file path = ", inputFilePath)
	log.Println("runs remaining to chase = ", runs)
	log.Println("overs left = ", overs)
	log.Println("wickets in hand = ", wickets)
	printLine()

	parseInput(inputFilePath)
}
