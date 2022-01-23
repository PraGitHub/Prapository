// Problem: https://www.hackerrank.com/challenges/ctci-ransom-note/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

fun checkMagazine(magazine: Array<String>, note: Array<String>): Unit {
    val sortedMagazine = magazine.sorted()
    val sortedNote = note.sorted()

    var prevFoundIndex = -1
    for (word in sortedNote) {
        val foundIndex = sortedMagazine.indexOf(word)
        if (foundIndex > prevFoundIndex) {
            prevFoundIndex = foundIndex
        } else {
            return println("No")
        }
    }
    println("Yes")
}