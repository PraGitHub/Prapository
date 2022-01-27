package essentials.interfaces

import kotlin.math.*

interface TwoDimenionalFigure {
    fun area(): Double
    fun perimeter(): Double
}

class Circle (val radius: Double): TwoDimenionalFigure {
    override fun area(): Double {
        return PI * radius * radius
    }
    override fun perimeter(): Double {
        return 2 * PI * radius
    }
    override fun toString(): String {
        return "Radius: ${radius}, Perimeter: ${this.perimeter()}, Area: ${this.area()}"
    }
}

class Square (val side: Double): TwoDimenionalFigure {
    var toPrint: String = ""
    override fun area(): Double {
        return side * side
    }
    override fun perimeter(): Double {
        return 4 * side
    }
    override fun toString(): String {
        return "Side: ${side}, Perimeter: ${this.perimeter()}, Area: ${this.area()}"
    }
}

fun main () {
    val c = Circle(5.0)
    val s = Square(9.0)
    println(c)
    println(s)
}