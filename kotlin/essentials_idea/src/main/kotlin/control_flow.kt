package essentials.control_flow

// Ternary equivalent is if and else
// Switch-case equivaltent is when-in and default is given by else

private fun ternary_and_case () {
    val a = 100
    val b = 10
    val greater = if (a > b) a else b
    println("Greater: ${greater}")

    val exp = 10
    val expGroup = when (exp) {
        in 0..2 -> "Associate"
        in 3..6 -> "Mid-Senior"
        in 6..10 -> "Senior"
        in 10..15 -> "Staff"
        else -> "Senior-Staff"
    }
    println("Experience: ${exp}, Group: ${expGroup}")

    val num = 5
    when (num%2) {
        0 -> println("${num} is even")
        1 -> println("${num} is odd")
    }
}

private fun max (a: Int, b: Int, c: Int): Int {
    // if block returns something which is quite unique to kotlin
    return (if (a > b && a > c) {
            a
        } else if (b > c) {
            b
        } else {
            c
        }
    )
}

private fun loops () {
     for (i in 1..10) {
        print("${i} ")
    }
    println()
    for (i in 10 downTo 1) {
        print("${i} ")
    }
    println()
    for (i in 1..10 step 2) {
        print("${i} ")
    }
    println()
    for (i in 10 downTo 1 step 2) {
        print("${i} ")
    }
    println()

    val animals = listOf("Lion", "Horse", "Elephant", "Camel", "Dog", "Tiger", "Leopard", "Rabbit", "Snake")

    for (animal in animals) {
        print("${animal} ")
    }
    println()
    for ((i, animal) in animals.withIndex()) {
        print("${i+1}: ${animal} ")
    }
    println()

    var i = 0
    val animal = "Dog"
    while (i < animals.size) {
        if (animals[i++].compareTo(animal) == 0){
            println("${animal} exists");
            break
        }
        if (i == animals.size) {
            println("{animal} does not exist")
        }
    }
}

// Safecall:
// If an object is doubted to be null and if we want to access any property of that object then we can use a "?" prior to the "."
// Example: person1?.age
//              If we use it as person1.age then it may crash the program if person1 is null
//              By using it this way => person1?.age, it returns a null without crashing the program
private fun null_case () {
    data class Person(var firstName: String, var lastName: String)

    // val person1: Person = null => We cannot assign null this way. We will get an error => error: null can not be a value of a non-null type Person
    val person1: Person? = null // If we jave to assign a null value to an object then we should have "?" with the declaration of type
    val person2: Person = Person (
        firstName = "Virat", 
        lastName = "Kohli"
    )

    // if (person1.firstName == null) { // We cannot access properties of nullable objects this way
    //     println("It's a miracle!")
    // }

    // We can use !! to access the property of a nullable object but this will crash the program. This is not a safecall
    // Exception in thread "main" java.lang.NullPointerException
    //     at essentials.control_flow.Control_flowKt.null_case(control_flow.kt:100)
    //     at essentials.control_flow.Control_flowKt.main(control_flow.kt:115)
    //     at essentials.control_flow.Control_flowKt.main(control_flow.kt)
    //
    // Hence, commenting below if block
    // if (person1!!.firstName == null) {
    //     println("It's a miracle!")
    // }

    if (person1?.firstName == null) { // Ths is the way to access properties of nullable objects
        println("Thanks to safecall")
    }
    println("Person 2: ${person2}")
    println("Person 2: ${person2.firstName} ${person2.lastName}")
}


private fun cardPoints (points: Int): String {
    return (
        if (points < 0) {
            "Invalid"
        } else {
            when (points) {
                in 0..999 -> "Pearl"
                in 1000..4999 -> "Silver"
                in 5000..9999 -> "Gold"
                else -> "Diamond"
            }
        }
    )
}

fun main () {
    ternary_and_case()
    println("Max(5, 9, 10) => ${max(5, 9, 10)}")
    println("Max(10, 10000, 9052)3 => ${max(10, -10000, 90523)}")
    loops()
    null_case()
    println("cardPoints(7_000) => ${cardPoints(7_000)}")
}