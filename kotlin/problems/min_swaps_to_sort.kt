// Complete the minimumSwaps function below.
fun minimumSwaps(arr: Array<Int>): Int {
    val arrWithPos: MutableList<Pair<Int, Int>> = mutableListOf()
    for (i in 0..(arr.size - 1)) {
        arrWithPos.add(Pair(arr[i], i))
    }
    val sortedArrWithPos = arrWithPos.sortedBy { it.first }.toMutableList()
    var swaps = 0
    var i = 0
    
    // println("arrWithPos: ${arrWithPos}")
    // println("sortedArrWithPos: ${sortedArrWithPos}")
        
    while (i < arrWithPos.size) {
        // println("sortedArrWithPos: ${sortedArrWithPos}")
        val unsortedPos = arrWithPos.get(i).second
        val sortedPos = sortedArrWithPos.get(i).second
        if (unsortedPos == sortedPos) {
            i++
            continue
        }
        
        val temp = sortedArrWithPos[i]
        sortedArrWithPos[i] = sortedArrWithPos[sortedPos]
        sortedArrWithPos[sortedPos] = temp
        
        swaps++
        // println("sortedArrWithPos: ${sortedArrWithPos}")
    }
    
    return swaps
}