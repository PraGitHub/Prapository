package main

import (
	"bufio"
	"io"
	"log"
	"os"
	"strconv"
	"strings"
)

type Batsman struct {
	name                                               string
	dots, ones, twos, threes, fours, fives, sixes, out float64
	score                                              int64
}

var batsmenData = []Batsman{}
var striker, nonStriker string

func printLine() {
	log.Println("--------------------------------------------------------------------------------")
}

func parseIntFromString(s string) int64 {
	n, err := strconv.ParseInt(s, 10, 64)
	if err != nil {
		printLine()
		log.Println("parseIntFromString :: err = ", err)
		log.Println("Given input = ", s, " is not a number")
		printLine()
		log.Fatalln("Please try again with right inputs")
	}
	return n
}

func parseFloatFromStirng(s string) float64 {
	n, err := strconv.ParseFloat(s, 64)
	if err != nil {
		printLine()
		log.Println("parseFromString :: err = ", err)
		log.Println("Given input = ", s, " is not a number")
		printLine()
		log.Fatalln("Please try again with right inputs")
	}
	return n
}

func getBatsman(name string) (batsman Batsman) {
	for i := range batsmenData {
		batsman = batsmenData[i]
		if batsman.name == name {
			break
		}
	}
	return
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
			Shashi Henra,30,25,5,0,5,1,4,30`)
	printLine()
	log.Println("40 is the number of runs remaining to  chase")
	printLine()
	log.Println("4 is the number of overs left")
	printLine()
	log.Println("3 is the number of wickets in hand")
	printLine()
	log.Fatalln("Please try again with right parameters")
}

func addToBatsmenData(keys, values []string) {
	sum := float64(0)
	var batsman Batsman
	for index, key := range keys {
		if key == "name" {
			batsman.name = values[index]
			if batsman.name == "" {
				printLine()
				log.Println("addToBatsmenData :: Batsman name is empty")
				printLine()
				log.Fatalln("Please try again with right inputs")
			}
			continue
		}

		value := parseFloatFromStirng(values[index])
		sum = sum + value
		//log.Println(name, " :: value = ", value, " sum = ", sum)
		value = value / float64(100)
		if key == "dots" {
			batsman.dots = value
		}
		if key == "ones" {
			batsman.ones = value
		}
		if key == "twos" {
			batsman.twos = value
		}
		if key == "threes" {
			batsman.threes = value
		}
		if key == "fours" {
			batsman.fours = value
		}
		if key == "fives" {
			batsman.fives = value
		}
		if key == "sixes" {
			batsman.sixes = value
		}
		if key == "out" {
			batsman.out = value
		}
	}
	//printLine()
	if sum != float64(100) {
		printLine()
		log.Println("sum of probability of batsman = ", batsman.name, " is not equal to 1, sum = ", sum)
		printLine()
		log.Fatalln("Please try again with right values of probabilities")
	}
	batsman.score = 0
	batsmenData = append(batsmenData, batsman)
}

func parseInput(inputFilePath string) {
	inFile, err := os.Open(inputFilePath)
	keys := make([]string, 0)
	values := make([]string, 0)
	if err != nil {
		printLine()
		log.Println("parseInput :: err while opening input file")
		log.Println("err = ", err)
		printLine()
		log.Fatalln("Please make sure the given file exists")
	}
	defer inFile.Close()

	reader := bufio.NewReader(inFile)
	firstLine := true
	length := 0
	for {
		bytes, _, err := reader.ReadLine()
		if err != nil {
			if err == io.EOF {
				break
			}
			printLine()
			log.Println("parseInput :: err while reading input file")
			log.Println("err = ", err)
			printLine()
			log.Fatalln("Please try again")
		}
		line := string(bytes)
		values = make([]string, 0)
		if firstLine {
			keys = strings.Split(line, ",")
			//log.Println("keys = ", keys)
			firstLine = false
			length = len(keys)
			continue
		}
		values = strings.Split(line, ",")
		if length != len(values) {
			printLine()
			log.Println("parseInput :: Invalid inputs ! Check input file")
			printLine()
			log.Fatalln("Please try again with right input file")
		}
		//log.Println("values = ", values)
		addToBatsmenData(keys, values)
	}
}

func simulateInnings() {
	log.Println("striker = ", striker, " nonStriker = ", nonStriker)
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
	log.Println("batsmenData = ", batsmenData)
	if len(batsmenData) <= 1 {
		printLine()
		log.Fatalln("All out !!!")
		printLine()
	}
	striker = batsmenData[0].name
	nonStriker = batsmenData[1].name
	simulateInnings()
}
