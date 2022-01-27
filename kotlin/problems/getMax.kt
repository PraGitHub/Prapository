// Problem: https://www.hackerrank.com/challenges/maximum-element/problem?isFullScreen=true

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

fun getMax(operations: Array<String>): Array<Int> {
    // Write your code here
    val max: List<Int>.() -> Int = {
        var max = Int.MIN_VALUE
        for (i in this) {
            max = if (i > max) i else max
        }
        max
    }
    var stack = mutableListOf<Int>()
    var output = mutableListOf<Int>()
    for (op in operations) {
        if (op == "3") {
            output.add(stack.max())
        }
        if (op == "2") {
            stack.removeAt(stack.size - 1)
        }
        if (op.contains("1 ")) {
            var num = op.subSequence(2, op.length).toString().toInt()
            stack.add(num)
        }
    }
    return output.toTypedArray()
}