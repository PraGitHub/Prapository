// Problem: https://www.hackerrank.com/challenges/abbr/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming

fun abbreviation(a: String, b: String): String {
    // Write your code here
    val aUpper = a.toUpperCase()
    var foundAt = -1
    // println(a)
    // println(aUpper)
    for (c in b) {
        var index = a.indexOf(c, foundAt + 1)
        index = if (index > foundAt) index else aUpper.indexOf(c, foundAt + 1)
        // println("c of b: ${c}, foundAt: ${foundAt}, index: ${index}")
        if ((index - foundAt) > 1) {
            val aInBetween = a.subSequence(foundAt + 1, index)
            // println(aInBetween)
            for (c in aInBetween) {
                if (c.isUpperCase()) {
                    return "NO"
                }
            }
        }
        foundAt = if (index > foundAt) index else -1
        // println(foundAt)
        if (foundAt == -1) {
            return "NO"
        }
    }
    if (foundAt < (a.length - 1)) {
        val aTail = a.subSequence(foundAt + 1, a.length)
        // println(aTail)
        for (c in aTail) {
            if (c.isUpperCase()) {
                return "NO"
            }
        }
    }
    return "YES"
}