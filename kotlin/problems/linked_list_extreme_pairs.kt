/*
Given list example => 1 -> 2 -> 3 -> 4
Output:
1,4
2,3
Given list example => 1 -> 2 -> 3 -> 4 -> 5 -> 6
Output:
1,6
2,5
3,4

Assume the length of list is always even
*/

data class Node (val value: Int) {
    var next: Node? = null
}

fun printList (head: Node?) {
    var temp = head
    print("List: ")
    while (temp != null) {
        print("${temp.value} ")
        temp = temp.next
    }
    println()
}

fun reverse (head: Node?): Node? {
    if (head == null) return null
    if (head.next == null) return head
    var pre = head
    var cur = head.next
    while(cur != null) {
        var temp = cur.next
        cur.next = pre
        pre = cur
        cur = temp
    }
    head.next = null
    // pre is the new head of reversed list
    return pre
}

fun printExtremes (head: Node?) {
    var len = 0
    var temp: Node? = head
    while (temp != null) {
        len++
        temp = temp.next
    }
    println("len: ${len}")
    temp = head
    for (i in 1..(len/2)) {
        temp = temp?.next
    }
    println("Second half begin: ${temp?.value}")
    var secondHalfBegin: Node? = reverse(temp)
    var firstHalf: Node? = head
    var secondHalf: Node? = secondHalfBegin
    println("Output:")
    while (secondHalf != null) {
        println("\t${firstHalf?.value}, ${secondHalf?.value}")
        firstHalf = firstHalf?.next
        secondHalf = secondHalf?.next
    }
    // By now, firstHalf would be equal to secondHalf start
    secondHalfBegin = reverse(secondHalfBegin)
    return
}

fun main () {
    val head: Node? = Node(1)
    val n = 10
    var prev = head
    var cur: Node
    for (i in 2..n) {
        cur = Node(i)
        cur.next = null
        prev?.next = cur
        prev = cur
    }
   	printList(head)
    printExtremes(head)
    printList(head)
}