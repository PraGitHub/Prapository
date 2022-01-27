package essentials.functions

private fun separate () {
    println("===============================================================")
}

fun area (x: Int, y: Int): Int = x * y

fun greater (a: Int, b: Int): Int = if (a > b) a else b

fun volume (x: Int, y: Int, z: Int = 1) = x * y * z

private fun lambdas () {
    val lam: (Int, Int) -> Int = { a: Int, b: Int -> a + b }
    val myLam = { a: Int, b: Int -> if (a % b == 0) true else false }

    println("lam(5, 6): ${lam(5, 6)}")
    println("myLam(15, 5): ${myLam(15, 5)}")
    println("myLam(15, 5): ${myLam.invoke(1995, 19)}")

    val greet: String.() -> String = { "Hello ${this}! Welcome to Kotlin World!" }
    val str_1 = "Virat Kohli"
    
    println(str_1.greet())
    println("Rob Pike".greet())

    val double: Int.() -> Int = { this * 2 }
    val halve: Int.() -> Int = { this / 2 }

    val myInt: Int = 10

    println("${myInt.double()}, ${myInt.halve()}")
    separate()
}

private fun anonymous_local () {
    val list = listOf(1, 2, 3, 4, 5, 6, 7 , 8)
    val zeroEvenList = list.map(fun (a: Int): Int {
        if (a % 2 == 0) return 0
        return a
    })
    val evenList = list.filter(fun (a: Int): Boolean {
        return a % 2 == 0
    })
    println("list: ${list}, zeroEvenList: ${zeroEvenList}, evenList: ${evenList}")

    fun factorial (n: Int): Long {
        var i = n.toLong()
        var fact: Long = 1L
        if (n < 0) fact = 0L
        while (i >= 1) {
            fact = fact * i--
        }
        return fact
    }

    println("factorial(-10): ${factorial(-10)}, factorial(0): ${factorial(0)}, factorial(5): ${factorial(5)}, factorial(10): ${factorial(10)}, factorial(15): ${factorial(15)}")

    val greater = lambda@{ a: Int, b: Int -> 
        if (a > b) return@lambda a 
        else return@lambda b
    }
    println("greater(7, 11): ${greater(7, 11)}")
    separate()
}

private fun replicate (func: (Int, String) -> Unit) {
    func (3, "Welcome to Kotlin World!")
} 

fun main () {
    println("area(4, 8): ${area(4, 8)}")
    println("greater(9, 11): ${greater(9, 11)}")
    println("volume(3, 4, 5): ${volume(3, 4, 5)}")
    println("volume(3, 4): ${volume(3, 4)}")
    separate()
    lambdas()
    anonymous_local()

    replicate (fun (n: Int, message: String) {
        var i = 0
        while (i++ < n) {
            println(message)
        }
    })

    replicate { n: Int, str: String ->
        println (str.repeat(n))
    }
    separate()
}