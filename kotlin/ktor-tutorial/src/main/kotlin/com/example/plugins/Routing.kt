package com.example.plugins

import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*

import kotlinx.serialization.*

@Serializable
data class Car(
    val name: String,
    val country: String
)

// This function configureRouting belongs to the class Application and hence it can be used directly in the Application.kt file
fun Application.configureRouting() {
    var cars = mutableMapOf(
        Pair("Volkswagen", "Germany"),
        Pair("Ford", "USA"),
        Pair("Hyundai", "South Korea"),
        Pair("Toyota", "Japan"),
        Pair("Fiat", "Italy")
    )

    routing {
        get("/") {
//            println(call.request.queryParameters)
//            println(call.parameters)
            call.respond("Welcome to Ktor! Try GET /home \uD83D\uDE03")
        }

        get("/home") {
            println("configureRouting /home GET")
            var res = "<h2> Select any one of them \uD83D\uDE03</h2>"
            res = res + "<ul> <li> <form action=\"/home/cars\"> <input type=\"submit\" value=\"JSON View\"> </form> </li> </ul>"
            for (key in cars.keys) {
                res = res + "<ul> <li> <form action=\"/home/${key}\"> <input type=\"submit\" value=\"${key}\"> </form> </li> </ul>"
            }
            call.respondText(res, ContentType.Text.Html)
        }

        get("/home/{car}") {
            val car = call.parameters.get("car")
            println("configureRouting /home GET: car = ${car}")
            val country = cars.get(car) ?: ""
            if (country == "") {
                call.respond(HttpStatusCode.BadRequest, "Bad Request. Passed parameter '${car}' is invalid.")
            } else {
                var res = "<h2> ${car} is from ${country} \uD83D\uDE03</h2>"
                res = res + "<form action=\"/home\"> <input type=\"submit\" value=\"Home\"> </form>"
                call.respondText(res, ContentType.Text.Html)
            }
        }

        post("/home/car") {
            var car = Car("", "")
            try {
                car = call.receive<Car>()
            }
            catch (err: Exception) {
                println("Error while parsing body: ${err}")
                return@post call.respondText("Invalid Body", status = HttpStatusCode.BadRequest)
            }
            println("Car given to add: ${car}")
            if (cars.get(car.name) == null) {
                cars.put(car.name, car.country)
                return@post call.respondText("Added ${car}")
            }
            call.respondText("Car: ${car} is already present")
        }

        get("/home/cars") {
            call.respond(cars)
        }
    }
}

