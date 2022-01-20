package essentials.classes

private fun separate () {
    println("===============================================================")
}

class PlainShort {}

class ShortClass

class WithConstructor constructor(name: String, age: Int) 

class WithoutConstructor (name: String, age: Int)

// Note: Both WithConstructor and WithoutConstructor are same

class MandatoryConstructor internal constructor(name: String, age: Int)
// internal means the class is pertained within the given kt file. When "internal" is used, we must use constructor keyword

// class MandatoryConstructor1 internal (name: String, age: Int)
// Above usage throws this error => classes.kt:16:29: error: use 'constructor' keyword after modifiers of primary constructor

// here courseTitle is not the property of the class CourseProperty
// title is the property of the class CourseProperty
class CourseProperty (courseTitle: String) {
    val title = courseTitle
}

// We can use val or var in the declaration of parameters so that they implicitly become propety of the class. Like below,
// firstName and age are properties of Person as they have val and var but lastName is not
class Person (val firstName: String, lastName: String, var age: Int)

class Course (courseTitle: String) {
    private val title = courseTitle
    internal var description = ""
    get () {
        return if (field.isNullOrBlank()) "No Description" else "${field}!"
    }

    fun show () {
        println(title)
    }

    override fun toString(): String {
        return "${title} - ${description}"
    }
}

class CourseWithoutToString (courseTitle: String) {
    private val title = courseTitle
    internal var description = ""
    get () {
        return if (field.isNullOrBlank()) "No Description" else "${field}!"
    }

    fun show () {
        println(title)
    }
}

private fun basics () {
    val p = Person ("Randy", "Orton", 40)
    // println("${p.firstName} ${p.lastName} @ ${p.age}") => this will throw => error: unresolved reference: lastName
    println("${p.firstName} @ ${p.age}")

    val course = Course("Kotlin Essentials")
    course.show() 
    course.description = "Nice way to know Kotlin" // as "description" is internal, it can be used in this file. but we cannot use title as it's private
    course.show() // This will print description as "Nice way to know Kotlin"
    println(course) // because of toString method which is overridden in Course, we will be able to print this

    val courseWithoutToString = CourseWithoutToString("Kotlin Essentials")
    courseWithoutToString.description = "Nice way to know Kotlin"
    courseWithoutToString.show()
    println(courseWithoutToString) // This will print the Unit of courseWithoutToString
    separate()
}

private fun constructors_and_init () {
    class Vehicle(
        val type: String,
        val brand: String,
        val model: String
    ) {
        override fun toString (): String {
            return "${type}: ${brand} ${model} ${engine} ${if (year == Int.MAX_VALUE) "" else year}"
        }

        // this gets called after the primary contructor is called
        // Only after calling init subsequent secondary contructor gets called
        init {
            println("First initializer block - $this")
        }

        // secondary constructor 1
        // secondary constructor has to call its previous constructor
        constructor(
            type: String,
            brand: String,
            model: String,
            engine: String
        ): this (type, brand, model) {
            this.engine = engine
        }

        // secondary constructor 2
        // notice that we are calling the previous constructor here
        constructor(
            type: String,
            brand: String,
            model: String,
            engine: String,
            year: Int
        ): this (type, brand, model, engine) {
            this.year = year
        }

        var engine: String = ""
        var year: Int = Int.MAX_VALUE
    }

    val v1 = Vehicle("Car", "Hyundai", "Eon")
    val v2 = Vehicle(type = "Scooter", model = "Activa", brand = "Honda")
    val v3 = Vehicle("Car", "Honda", "WR-V", "Petrol")
    val v4 = Vehicle("Motor Bike", "Suzuki", "Gixer", "Petrol", 2022)
    println(v1)
    println(v2)
    println(v3)
    println(v4)
    separate()
}

private fun data_classes () {
    // data class is very useful in assigning objects to another, comparing objects, etc without having to overrite equals, assign, etc. methods
    // if we had Vehicle defined as just a class then we would have to override various methods depending on our needs. 
    // For example, if we had to compare if 2 Vehicles are equal then we had to override equals method
    data class Vehicle (val type: String, val brand: String, val model: String)
    val v1 = Vehicle ("Car", "Hyundai", "i10")
    val v2 = v1
    val v3 = Vehicle ("Car", "Honda", "Brio")

    println("v1: ${v1}, v2: ${v2}, v3: ${v3}")
    println("v1 == v2: ${v1 == v2}")
    println("v2 == v3: ${v2 == v3}")
    separate()
}

fun main () {
    basics()
    constructors_and_init()
    data_classes()
}