package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

// Complete the arrayManipulation function below.
func arrayManipulation(n int32, queries [][]int32) int64 {
    /*var max_value int32
    max_value = 0

    arr := make([]int32,n)

    //fmt.Println("arr = ",arr)

    //fmt.Println("len(queries) = ",len(queries))
    //fmt.Println("queries = ",queries)

    for i:=0;i<len(queries);i++{
        query := queries[i]
        //fmt.Println(i," : query = ",query)
        begin := query[0]
        end := query[1]
        value := query[2]
        for j:=begin;j<=end;j++{
            arr[j-1] = arr[j-1] + value
        }
    }

    max_value = arr[0]
    for i:=1;i<len(arr);i++{
        if max_value<arr[i]{
            max_value = arr[i]
        }
    }*/

    arr := make([]int64,n)
    
    for _,query := range queries{
        arr[query[0]-1] = arr[query[0]-1] + int64(query[2])
        if query[1] < n{
            arr[query[1]] = arr[query[1]] - int64(query[2])
        }
        //fmt.Println("arr = ",arr)
    }

    //fmt.Println("arr = ",arr)

    max_value := arr[0]

    for i:=int32(1); i<n ;i++{
        arr[i] = arr[i] + arr[i-1]
        if max_value<arr[i]{
            max_value = arr[i]
        }
    }

    //fmt.Println("arr = ",arr)
    //fmt.Println("max_value = ",max_value)

    return max_value
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer stdout.Close()

    writer := bufio.NewWriterSize(stdout, 1024 * 1024)

    nm := strings.Split(readLine(reader), " ")

    nTemp, err := strconv.ParseInt(nm[0], 10, 64)
    checkError(err)
    n := int32(nTemp)

    mTemp, err := strconv.ParseInt(nm[1], 10, 64)
    checkError(err)
    m := int32(mTemp)

    var queries [][]int32
    for i := 0; i < int(m); i++ {
        queriesRowTemp := strings.Split(readLine(reader), " ")

        var queriesRow []int32
        for _, queriesRowItem := range queriesRowTemp {
            queriesItemTemp, err := strconv.ParseInt(queriesRowItem, 10, 64)
            checkError(err)
            queriesItem := int32(queriesItemTemp)
            queriesRow = append(queriesRow, queriesItem)
        }

        if len(queriesRow) != int(3) {
            panic("Bad input")
        }

        queries = append(queries, queriesRow)
    }

    result := arrayManipulation(n, queries)

    fmt.Fprintf(writer, "%d\n", result)

    writer.Flush()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
