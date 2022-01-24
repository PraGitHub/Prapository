// Problem: https://www.hackerrank.com/challenges/angry-children/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms

fun maxMin(k: Int, arr: Array<Int>): Int {
    // Write your code here
    arr.sort()
    var min = Int.MAX_VALUE
    for (i in 0..(arr.size - k)) {
        val maxMinDiff = arr[i+k-1] - arr[i]
        min = if (maxMinDiff < min) maxMinDiff else min
    }
    return min
}