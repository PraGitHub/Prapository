fun minimumAbsoluteDifference(arr: Array<Int>): Int {
    // Write your code here
    arr.sort()
    // println(arr)
    var minDiff = Int.MAX_VALUE
    for (i in 1..(arr.size - 1)) {
        var diff = arr[i] - arr[i - 1]
        diff = if (diff < 0) -diff else diff
        minDiff = if (diff < minDiff) diff else minDiff
    }
    return minDiff
}