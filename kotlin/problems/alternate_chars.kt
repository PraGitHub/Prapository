// Problem: https://www.hackerrank.com/challenges/alternating-characters/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings

fun alternatingCharacters(s: String): Int {
    // Write your code here
    var count = 0
    for ( i in s.indices ) {
        if (i == 0) {
            continue
        }
        if (s[i] == s[i-1]) {
            count++
        }
    }
    return count
}
