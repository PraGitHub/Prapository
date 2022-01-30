package com.example.plugins

import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*

// This function configureRouting belongs to the class Application and hence it can be used directly in the Application.kt file
fun Application.configureRouting() {
    val cars = mapOf(
        Pair("Volkswagen", "Germany"),
        Pair("Ford", "USA"),
        Pair("Hyundai", "South Korea"),
        Pair("Toyota", "Japan"),
        Pair("Fiat", "Italy")
    )

    routing {
        get("/home") {
            println("configureRouting /home GET")
            var res = "<h2> Select any one of them \uD83D\uDE03 </h2>"
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
                var res = "<h2> ${car} is from ${country} \uD83D\uDE03 </h2>"
                res = res + "<form action=\"/home\"> <input type=\"submit\" value=\"Home\"> </form>"
                call.respondText(res, ContentType.Text.Html)
            }
        }
    }
}
