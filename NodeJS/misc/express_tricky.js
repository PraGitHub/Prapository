const express = require('express');
const app = express();

const PORT = 1234;
const HOST = '127.0.0.1';

var resJsonBasic = {
    server: {
        port: PORT,
        host: HOST
    },
    author: {
        name: 'Prashanth'
    },
    message: {
        handler: '',
        method: '',
        url: ''
    }
};

/*
With this order, i.e, app.get, app.post and app.all on route /myRoute, any POST or GET call made on /myRoute is handled by the handler registered via app.all
If the order is like this => app.all, app.get and app.post then, POST call is handled by app.post handler, GET call is handled by app.get handler and any other method is handled by app.all handler
If the order is like this => app.get, app.all, app.post then, GET call is handled by app.all handler, POST call is handled by app.post handler and rest of the methods is handled by app.all handler

So, the funda is that, the latest declared handler for the route is what gets considered/registered.

Also, if we move the app.use past above all the method-route-handler declaration, then, app.use gets executed prior to any handler
With app.use is in the end, it gets executed after executing the handler

So, the funda about declaration of middlewares is that, 
If we want any of the middlewares to be executed prior to the execution of the handler of a route then we should have the middleware declared above the declaration of route-method handler.
If we want any of the middlewares to be executed after the execution of the handler of a route then we should have the middleware declared below the declaration of route-method handler.
*/

app.get('/myRoute', (req, res, next) => {
    req.message = {
        handler: 'app.get',
        method: req.method,
        url: req.url
    };
    next();
});

app.post('/myRoute', (req, res, next) => {
    req.message = {
        handler: 'app.post',
        method: req.method,
        url: req.url
    };
    next();
});

app.all('/myRoute', (req, res, next) => {
    req.message = {
        handler: 'app.all',
        method: req.method,
        url: req.url
    };
    next();
});

app.use((req, res, next) => {
    var resJson = resJsonBasic;
    resJson.message = req.message;
    res.json(resJson);
});

app.listen(PORT, HOST, (err) => {
    if (err) {
        console.log('Error starting express server:', err);
    } else {
        console.log(`Running express server on ${HOST}:${PORT}`);
    }
});
