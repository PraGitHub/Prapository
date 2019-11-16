const async = require('async');
const randString = require('./randString');

const toLower = (str, callback) => {
    callback(null, str.toLowerCase());
}

const ovalExists = (str, callback) => {
    callback(null,
        (
        str.indexOf('a') >= 0 ||
        str.indexOf('e') >= 0 ||
        str.indexOf('i') >= 0 ||
        str.indexOf('o') >= 0 ||
        str.indexOf('u') >= 0
    ));
}

const rndStr = randString(10);

const composeObj = async.compose(ovalExists, toLower);

composeObj(rndStr, (err, result) =>{
    if(err){
        console.log('compose callback :: err = ', err);
    }else{
        if(result){
            console.log(`compose callback :: ${rndStr} has an oval`);
        }else{
            console.log(`compose callback :: ${rndStr} doesn't have an oval`);
        }
    }
});

const seqObj = async.seq(toLower, ovalExists);

seqObj(rndStr, (err, result) => {
    if (err) {
        console.log('seq callback :: err = ', err);
    } else {
        if (result) {
            console.log(`seq callback :: ${rndStr} has an oval`);
        } else {
            console.log(`seq callback :: ${rndStr} doesn't have an oval`);
        }
    }
});
