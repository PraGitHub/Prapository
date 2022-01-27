// Problem: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

/*
 * Complete the 'chocolateFeast' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c
 *  3. INTEGER m
 */

fun chocolateFeast(n: Int, c: Int, m: Int): Int {
    // Write your code here
    var sum = 0
    var inHand = n/c
    sum += inHand
    
    if (inHand < m) {
        return sum
    }
    
    if (inHand == m) {
        return (sum + 1)
    }

    var canGet = inHand/m
    
    while (canGet > 0) {
        sum += canGet
        inHand = canGet + inHand % m
        canGet = inHand/m
    }
    
    return sum
}