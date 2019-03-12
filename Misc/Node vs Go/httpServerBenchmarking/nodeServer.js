var express = require('express')
var app = express()
var count = 0

app.listen(8085)

app.get('/',function(req,res){
    count = count + 1
    res.send("node server :: client no "+ count)
})