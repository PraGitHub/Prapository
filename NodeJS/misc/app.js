const express = require('express');
const bodyParser = require('body-parser');
const routes = require('./api/routes');

const PORT = 1234;
const HOST = '127.0.0.1';

const app = express();
const router = express.Router();

app.use(bodyParser.urlencoded({extended: true}));
app.use(bodyParser.json());

app.use('/api', router);
routes(router);

app.get('/special', (req, res) => {
    console.log('Inside special');
    res.json({
        author: 'Prashanth',
        messsage: `You have reached the special handler ${req.method} ${req.url}`
    });
});

app.all('/*', (req, res, next) => {
    console.log('Inside all');
    req.output = {
        author: 'Prashanth',
        messsage: `You have reached the common handler ${req.method} ${req.url}`
    };
    next();
});

app.use((req, res, next) => {
    console.log('Inside final middleware');
    if (req.output) {
        res.json(req.output);
    }
});

app.listen(PORT, HOST, (err) => {
    if (!err) {
        console.log(`Express server running on ${HOST}:${PORT}`);
    } else {
        console.log('Error starting express server:', err);
    }
});

