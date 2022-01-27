package essentials.challenge

class Bosco () {
    init {
        count++
    }
    companion object {
        private var count = 0
        fun show() {
            println("Bosco.show: ${count}")
        }
    }
}

fun nop () {
    val b = Bosco()
}

fun main () {
    val b1 = Bosco()
    val b2 = Bosco()
    nop()
    val b3 = Bosco()
    Bosco.show() // should print the number of objects Bosco has 
}