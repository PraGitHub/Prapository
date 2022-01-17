package essentials.strings

fun main () {
    var str1 = "prashanth"
    var str2 = "kotlin"

    println("${str1.compareTo(str2)}")
    println("${str2.compareTo(str1)}")
    println("${str1.compareTo(str1)}")

    println("${str1}.get(2) => ${str1.get(2)}")
    println("${str1}[2] => ${str1[2]}")
    
    println("${str1}.subSequence(2,5) => ${str1.subSequence(2,5)}")

    for (char in str2) {
        print("$char ")
    }
    println()

    var raw_string = """
    Hello World!
    This is raw string from kotlin.
                            - Prashanth
    """
    println(raw_string)
}