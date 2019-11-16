const async = require('async');
const randString = require('./randString');

const arr = [
    'first',
    'second',
    'third',
    'fourth',
    'fifth'
];

var index = 0;

async.whilst(
    () => {
        console.log((index < arr.length));
        return (index < arr.length);
    },
    (callback) => {
        var result = {
            name: arr[index],
            str: randString()
        };
        index++;
        callback(null, result);
    },
    (err) => {
        if(err){
            console.error(err);
        }else{
            console.log(`Job ${result.name} completed. str = ${result.str}`);
        }
    }
);

