package com.example

import io.ktor.server.engine.*
import io.ktor.server.netty.*
import com.example.plugins.*

import io.ktor.routing.*
import io.ktor.http.*
import io.ktor.application.*
import io.ktor.response.*
import io.ktor.request.*

fun main() {
    embeddedServer(Netty, port = 8080, host = "localhost") {
        install(Routing) {
            homeRoute()
        }
        configureRouting()  // We are importing Routing.kt here with import com.example.plugins.* and,
                            // it has definition of configureRouting function which is tied to Application class
    }.start(wait = true)
}

fun Routing.homeRoute() {
    get("/") {
        println("homeRoute GET")
        call.respond("Welcome to Ktor! Try to GET /home \uD83D\uDE03")
    }
}
