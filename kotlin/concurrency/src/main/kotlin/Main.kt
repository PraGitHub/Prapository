import kotlinx.coroutines.*
import kotlin.system.measureTimeMillis

suspend fun ioOrNetworkCall (time: Long = 1L) {
    delay(time)
    println("After ${time} ms: From ${Thread.currentThread().name} thread")
}

fun main () {
    GlobalScope.launch {
        ioOrNetworkCall(10L)
        ioOrNetworkCall()
        ioOrNetworkCall(20L)
        ioOrNetworkCall(60L)
    }
    Thread.sleep(200L)
    println("Done: From ${Thread.currentThread().name} thread")
}