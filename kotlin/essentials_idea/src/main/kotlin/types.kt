package essentials.types

// var: mutable
// val: immutable

private fun numbers_bool () {
    var count: Int = 0

    val number: Int = 42
    val otherNumber = 43

    val myLong: Long = 3000000000L
    val myByte: Byte = 127
    val myShort: Short = 32767

    val myDouble: Double = 99.9
    val myFloat: Float = 12.6F
    val alsoDouble = 101.5

    val asInt = alsoDouble.toInt()
    val asFloat = myLong.toFloat()

    val maxInt = 2_147_483_648

    val myBoolean: Boolean = true

    println("$count, $number, $otherNumber")
    println("$myLong, $myByte, $myShort")
    println("$myDouble, $myFloat, $alsoDouble")
    println("$asInt, $asFloat, $alsoDouble, $maxInt")
    println("$myBoolean ${!myBoolean}")
}

private fun char_strings () {
    val myString: String = "prashanth"
    val myChar: Char = 'P'

    println("$myString, $myChar")

    var myStringTemp: String
    // using var as we need to assign something to myStringTemp several times
    // if we use val then, we cannot assing things to myStringTemp more than once
    // Error that we may get iwth val and multiple assignments: "error: val cannot be reassigned"
    myStringTemp = myString.plus("_").plus(myChar.toString()); 
    println("$myStringTemp")
    myStringTemp = ""
    myStringTemp = myString + "_" + myString;
    println("$myStringTemp")
    myStringTemp = ""
    myStringTemp = "${myString}_${myString}";
    println("$myStringTemp")
}

fun main () {
    println("Hello World!")
    numbers_bool();
    char_strings();
}