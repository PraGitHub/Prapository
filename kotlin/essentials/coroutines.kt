package essentials.coroutines

import kotlinx.coroutines.*
import kotlin.system.measureTimeMillis

// need to complete this

suspend fun waiter(i: Int): Int {
    delay(1000)
    return i
}

fun synchronous() = runBlocking {
    val a = waiter(1)
    val b = waiter(2)
    val c = waiter(3)
    println("$a, $b, $c")
}

fun main () {
    val time = measureTimeMillis {
        synchronous()
    }
    println("time: ${time}")
}