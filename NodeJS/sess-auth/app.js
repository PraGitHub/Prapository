const express = require('express')
const session = require('express-session')
const app = express()
const maxSessAge = 2 * 60 * 60 * 1000 // 2 hrs

app.use(session({
    name: 'sid',
    resave: false,
    saveUninitialized: false,
    secret: 'sess-auth_server_secret',
    cookie: {
        maxAge: maxSessAge,
        sameSite: true,
        secure: false
    }
}));

app.listen(8085,'localhost',function(err){
    if(err){
        console.log("app.listen :: err = ",err);
        process.exit(0);
    }
    console.log('server is running ...');
});

app.get('/', function(req,res){
    res.send({
        'server':'sess-auth server',
        'place':'Bengaluru',
        'message':'Hello !!!'
    });
});

app.get('/dashboard', function(req, res){

});

app.get('/login', function(req, res){

});

app.get('/register', function(req, res){

});

app.post('/login', function(req, res){

});

app.post('/register', function(req, res){

});

app.post('/logout', function(req, res){

});