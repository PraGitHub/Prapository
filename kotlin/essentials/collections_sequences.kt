package essentials.collections_sequences

data class Person (var firstName: String, var lastName: String)

private fun arrays () {
    // Heterogenour array
    val things = arrayOf(1, 2, 3, "Hello", "world", true, Person("Ravi","Verma"))

    // Homogenous array
    val persons = arrayOf<Person>(
        Person("Virat", "Kohli"),
        Person("Raj", "Kapoor"),
        Person("Narendra", "Modi"),
        Person("Ananth", "Nag")
    )

    println (things)
    for (thing in things) {
        print("${thing} ")
    }
    println()

    println(persons)
    for ((index, person) in persons.withIndex()) {
        println("${index + 1}. ${person.firstName} ${person.lastName}")
    }
    // Traverse using forEach
    // forEach gives "it", which holds each item in each iteration
    persons.forEach {
        println (it);
    }
}

fun main () {
    arrays()
}