var express = require('express')
var app = express()

app.listen(8085)

app.get('/',function(req,res){
    res.send("This is node server")
})