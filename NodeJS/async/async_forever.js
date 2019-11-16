const async = require('async');
const randString = require('./randString');

const exitCondition = (str) => {
    str = str.toLowerCase();
    return (
        str.indexOf('pra') >= 0
    );
}

async.forever((next) => {
    const str = randString(100);
    var exit = exitCondition(str);
    console.log(`str = ${str}, exit = ${exit}`);
    if(exit){
        next('exiting ...');
    }else{
        next();
    }
}, (err) => {
    if(err){
        console.error(err);
    }else{

    }
});