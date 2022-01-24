// Problem: https://www.hackerrank.com/challenges/frequency-queries/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

// Complete the freqQuery function below.
fun freqQuery(queries: Array<Array<Int>>): Array<Int> {
    var hash = HashMap<Int, Int>()
    var list = mutableListOf<Int>()
    for (query in queries) {
        val operation = query[0]
        val num = query[1]
        var count = hash.get(num)?.toInt()
        if (count == null) {
            count = -1
        } 
        if (operation == 1) {
            if (count == -1) {
                hash.put(num, 1)
            } else {
                hash.replace(num, count + 1)
            }
        }
        if (operation == 2) {
            if (count > 1) {
                hash.replace(num, count - 1)
            } 
            if (count == 1) {
                hash.remove(num)
            }
        }
        if (operation == 3) {
            var found = 0
            for (key in hash.keys) {
                var freq = hash.get(key)?.toInt()
                if (freq == null) {
                    freq = 0
                }
                if (freq >= num) {
                    found = 1
                    break
                }
            }
            list.add(found)
        }
    }
    // println(hash)
    return list.toTypedArray()
}