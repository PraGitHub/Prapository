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

app.all('/*', (req, res, next) => {
    console.log('Inside all');
    req.message = {
        handler: 'app.all',
        method: req.method,
        url: req.url
    };
    next();
});

app.get('/myRoute', (req, res, next) => {
    console.log('Inside get');
    req.message = {
        handler: 'app.get',
        method: req.method,
        url: req.url
    };
    next();
});

app.post('/myRoute', (req, res, next) => {
    console.log('Inside post');
    req.message = {
        handler: 'app.post',
        method: req.method,
        url: req.url
    };
    next();
});

app.use((req, res, next) => {
    console.log('Inside final middleware');
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
