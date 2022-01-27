package essentials.collections_sequences

data class Person (var firstName: String, var lastName: String)

private fun separate () {
    println("===============================================================")
}

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
    separate()
}

private fun lists () {
    var names = listOf("Undertaker", "Kane", "HBK", "HHH")
    // Following 2 lines won't work for an immutable list
    // names.set(0, "Batista")
    // names[0] = "Batista"

    var mutable_names = mutableListOf("Randy")
    names.forEach {
        mutable_names.add(it)
    }
    println(mutable_names.subList(0, 5))

    mutable_names[0] = "Batista"
    mutable_names[1] = "Cena"
    println(mutable_names)

    println("Removed: ${mutable_names.removeAt(2)}")
    println("Removing Edge: ${mutable_names.remove("Edge")}")
    println("Adding Undertaker: ${mutable_names.add("Undertaker")}")
    println(mutable_names)
    println("Adding Edge: ${mutable_names.add("Edge")}")
    println("Adding Edge: ${mutable_names.add("Edge")}")
    println(mutable_names)
    println("Removing Edge with .remove: ${mutable_names.remove("Edge")}") // Remove only removes one entry of an item that has occurred multiple times
    println(mutable_names)
    println("Adding Edge: ${mutable_names.add("Edge")}")
    println(mutable_names)

    // To remove all occurances of an element then we should use .contains method along with .remove with a while loop
    while (mutable_names.contains("Edge")) {
        mutable_names.remove("Edge")
    }
    println("After while loop to remove Edge: ${mutable_names}")

    println("Adding Edge: ${mutable_names.add("Edge")}")
    println("Adding Edge: ${mutable_names.add("Edge")}")
    println(mutable_names)

    // To remove all occurances of an element then we can also use removeAll
    mutable_names.removeAll(listOf("Edge"))
    println("After removeAll to remove Edge: ${mutable_names}")
    separate()
}

private fun sets () {
    val mySet = setOf(3, 3, 3, 3, 2, 2, 1, 1, 1, 7, 7, 7, 7, 7, 9, 10)
    println("mySet.size: ${mySet.size}, mySet: ${mySet}") // only one occurance is printed as sets always hold unique elements

    val list_1 = mutableListOf(1, 2, 3)
    val list_2 = mutableListOf(3, 2, 1)
    println("list_1 == list_2: ${list_1 == list_2}") // prints false as oder matters in a list for us to say that the lists are equal

    val set_1 = mutableSetOf(1, 2, 3)
    val set_2 = mutableSetOf(3, 2, 1)
    println("set_1: ${set_1}, set_2: ${set_2}") // prints both sets in the order in which they have been built
    println("set_1 == set_2: ${set_1 == set_2}") // prints true as order does not matter for us to say that sets are equal

    val hset_1 = hashSetOf(1, 2, 3)
    val hset_2 = hashSetOf(3, 2, 1)
    println("hset_1: ${hset_1}, hset_2: ${hset_2}") // prints both sets in the same order as hash set stores elements in a particular order
    println("hset_1 == hset_2: ${hset_1 == hset_2}") // prints true as order does not matter for us to say that sets are equal
    separate()
}

private fun maps () {
    val map_1 = mapOf(1 to "apple", "ball" to 2, 3 to "cat")
    val map_2 = mapOf("ball" to 2, 3 to "cat", 1 to "apple")
    println("map_1: ${map_1}, map_2: ${map_2}")
    println("map_1 == map_2: ${map_1 == map_2}")

    // hasMap is not like hashSet
    val hmap_1 = hashMapOf(1 to "apple", "ball" to 2, 3 to "cat")
    val hmap_2 = hashMapOf("ball" to 2, 3 to "cat", 1 to "apple")
    println("hmap_1: ${hmap_1}, hmap_2: ${hmap_2}")
    println("hmap_1 == hmap_2: ${hmap_1 == hmap_2}")

    val mutable_map_1 = mutableMapOf(1 to "apple", "ball" to 2, 3 to "cat")
    val mutable_map_2 = mutableMapOf("ball" to 2, 3 to "cat", 1 to "apple")
    println("mutable_map_1: ${mutable_map_1}, mutable_map_2: ${mutable_map_2}")
    println("mutable_map_1 == mutable_map_2: ${mutable_map_1 == mutable_map_2}")

    for (key in map_1.keys) {
        print("${key} ")
    }
    println()
    for (value in map_1.values) {
        print("${value} ")
    }
    println()
    for ((key, value) in map_1) {
        print("${key}: ${value} ")
    }
    println()

    println("ball in map_1: ${"ball" in map_1}")
    separate()
}

private fun operations () {
    val myList = listOf(6, 8, 4, 3, 7, 1, 5, 2)
    println("myList: ${myList}")
    
    val evenOdd = myList.map {
        if (it % 2 == 0) "${it} is even" else "${it} is odd"
    }
    println("evenOdd: ${evenOdd}")

    println(Pair("alpha", 1))

    val evenOddMap = myList.map {
        Pair(it, if(it%2 == 0) "Even" else "Odd")
    }.toMap()
    println("evenOddMap: ${evenOddMap}")

    val myMap = mapOf(
        Pair("Bengaluru", "Karnataka"),
        Pair("Pune", "Maharashtra"),
        Pair("Kanpur", "Uttar Pradesh"),
        Pair("Kochin", "Kerala"),
        Pair("Ahmedabad", "Gujarat"),
    )
    println("myMap: ${myMap}")
    val myMapTransformed = myMap.map {
        mapOf(
            Pair("City", it.key),
            Pair("State", it.value)
        )
    }
    println("myMapTransformed: ${myMapTransformed}")

    val oddList = myList.filter {
        it % 2 == 1
    }
    val evenList = myList.filter {
        it % 2 == 0
    }
    println("oddList: ${oddList}")
    println("evenList: ${evenList}")

    println("myList.sorted(): ${myList.sorted()}")
    println("myList.sortedDescending(): ${myList.sortedDescending()}")

    println("myMap.toSortedMap(): ${myMap.toSortedMap()}")
    separate()
}

private fun sequences () {
    val myList = (50 downTo 1)
    val divisibleBySeven = myList
    .asSequence()
    .map {
        // println("Determining Odd or Even")
        Pair(it, if(it % 2 == 0) "Even" else "Odd")
    }
    // This won't print the mapped version because there is no terminal operation such as toMap or toList being called on the result
    // This is because of asSequence
    println("divisibleBySeven: ${divisibleBySeven}") // Prints something like this => divisibleBySeven: kotlin.sequences.TransformingSequence@41629346
    val divisibleBySevenMap = divisibleBySeven
    .toMap()
    .filter {
        // println("Determining if divisible by 7")
        it.key % 7 == 0
    }
    .toSortedMap()

    println("divisibleBySevenMap: ${divisibleBySevenMap}")
    separate()
}

private fun removeDuplicate (list: List<Any>): List<Any> {
    return list
    .toSet()
    .toList()
}

// Lists, Sets, Maps => Collections
fun main () {
    separate()
    arrays()
    lists()
    // sets is to have collection of unique elements
    // In lists and arrays we can have multiple occurrances of same item/element
    sets()
    maps()
    operations()
    sequences()

    var list: List<Any> = listOf("apple", "biscuit", "apple", "cat","cat", "goat", "fox", "cat", "fox", "biscuit", "elephant")
    println("list: ${list}")
    println("removeDuplicate(list): ${removeDuplicate(list)}")

    list = listOf(100, 200, 100, 100, 300, 700, 600, 600, 400, 300, 400, 500, 900, 500, 200, 700, 700, 700, 600, 300, 100)
    println("list: ${list}")
    println("removeDuplicate(list): ${removeDuplicate(list)}")
    separate()
    System.exit(0)
}