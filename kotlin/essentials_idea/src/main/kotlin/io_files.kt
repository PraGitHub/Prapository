package essentials.io_files

import java.util.Scanner
import java.io.File

private fun separate () {
    println("===============================================================")
}

private fun printArgs (args: Array<String>) {
    args
    .toList()
    .sorted()
    .forEach {
        print("${it} ")
    }
    println()
    separate()
}

private fun readInputs () {
    print("Enter text: ")
    var text = readLine() ?: ""
    println("Entered text: ${text}, Length: ${text.length}")

    print("Enter Int: ")
    var numStr = readLine() ?: ""
    val num = numStr.toIntOrNull() // here the inferred type is Int?
    if (num == null) {
        println("Entered null")
    } else {
        println("Entered num: ${num}")
    }
    val num_1: Int = numStr.toIntOrNull() ?: Int.MAX_VALUE // if we strictly want it to be Int then we should handle it with elvis operator
    println("Entered num: ${num_1}")

    print("Enter Double: ")
    numStr = readLine() ?: ""
    val dValue: Double = numStr.toDoubleOrNull() ?: Double.MAX_VALUE // if we strictly want it to be Int then we should handle it with elvis operator
    println("Entered dValue: ${dValue}")
    separate()
}

private fun scanner () {
    val scan = Scanner(System.`in`) // should import java.util.Scanner
    print("Enter Integer: ")
    val num1 = scan.nextInt()
    print("Enter Double:")
    val num2 = scan.nextDouble()
    println("num1: ${num1}, num2: ${num2}")
    separate()
}

private fun files () {
    val inFilePath = "src/main/resources/data/input.txt"
    val outFilePath = "src/main/resources/data/output.txt"

    val inFile = File(inFilePath)
    val outFile = File(outFilePath)

    var list: MutableList<Map<String, String>> = mutableListOf()

    inFile.forEachLine {
        if (!it.contains(" ")) return@forEachLine
        var cmd_end = it.indexOf(" ")
        var cmd = it.subSequence(0, cmd_end)
        var param = it.substring(cmd_end + 1, it.length)
        // println("cmd: ${cmd}, param: ${param}")
        val cmdMap = mapOf(
            Pair("command", cmd.toString()), // cmd will be CharSequence as we used subSequence
            Pair("parameters", param) // param will be String as we used substring
        )
        // println("cmdMap: ${cmdMap}")
        list.add(
            cmdMap
        )
    }
    println("list: ${list}")

    if (outFile.exists()) {
        outFile.writeText("")
    }
    
    list.forEach {
        outFile.appendText("Command: ${it.get("command")}\nParameters: ${it.get("parameters")}\n\n")
    }
    separate()
}

private fun parseNumbers () {
    val inFilePath = "src/main/resources/data/numbers.txt"
    val outFilePath = inFilePath + ".filtered"

    val inFile = File(inFilePath)
    val outFile = File(outFilePath)

    if (!inFile.exists()) {
        return
    }

    if (outFile.exists()) {
        outFile.writeText("")
    }

    val numList: MutableList<Int> = mutableListOf()

    inFile.forEachLine {
        val num: Int? = it.toIntOrNull()
        if (num == null) {
            return@forEachLine
        }
        numList.add(num)
    }

    println("numList: ${numList}")

    numList.forEach {
        outFile.appendText("${it}\n")
    }
    separate()
}

fun main (args: Array<String>) {
    printArgs(args)
    readInputs()
    scanner()
    files()
    parseNumbers()
}