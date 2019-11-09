const async = require('async');

var json = {};

const funcOne = (callback) => {
    var date = new Date().toISOString();
    console.log('funcOne calling callback');
    callback(null, date);
}

const funcTwo = (callback) => {
    var date = new Date().toUTCString()
    //executing the callback in next cycle of event loop to demonstrate that the array of functions are executing one after the other
    async.setImmediate(() => {
        console.log('funcTwo calling callback');
        callback(null, date);
    });
}

const funcThree = (callback) => {
    var date = new Date().toString();
    console.log('funcThree calling callback');
    callback(null, date);
}

const funcFour = (callback) => {
    var millis = new Date().getMilliseconds();
    console.log('funcFour calling callback');
    callback(null, millis);
}

json.toISOString = funcOne;
json.toUTCString = funcTwo;
json.toString = funcThree;
json.timeInMillis = funcFour;

//console.log(json);

async.series(
    json,
    (err, result) => {
        if (err) {
            console.error(err);
        } else {
            console.log('result = ', result);
        }
    }
)
