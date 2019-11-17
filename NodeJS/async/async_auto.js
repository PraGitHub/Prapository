const async = require('async');
const randString = require('./randString');

const pwHash = (str) => {
    return randString(50);
}

// use async auto to illustrate user login logic

const login = (username, password) => {
    async.auto({
            processUserData: (callback) => {
                var userData = {
                    userid: username.toLowerCase(),
                    pw: pwHash(password)
                };
                console.log(`processUserData :: Processed user = ${username}'s data`);
                console.log('processUserData :: userdata = ', userData);
                callback(null, userData);
            },
            connectToDb: (callback) => {
                setTimeout(() => {
                    console.log('connectToDb :: connected to db');
                    callback(null, {
                        connected: true
                    });
                }, 1000);
            },
        lookUpUser: ['processUserData', 'connectToDb', (results, callback) => {
                setTimeout(() => {
                    console.log(`lookUpUser :: Inputs = 
                    userid = ${results.processUserData.userid}
                    pw = ${results.processUserData.pw}
                    connected to db = ${results.connectToDb.connected}
                    `);
                    if(results.connectToDb.connected){
                        callback(null, {
                            userFound: ((new Date().getMilliseconds()) % 2 == 0)
                        });
                    }else{
                        callback('lookUpUser :: db connection failed', null);
                    }
                }, 1000);
            }],
        dologin: ['lookUpUser', (results, callback) => {
                if(results.lookUpUser.userFound){
                    console.log(`dologin :: user found`);
                    callback(null, {
                        status: 200,
                        message: 'User found'
                    });
                }else{  
                    console.log(`dologin :: user not found`);
                    callback(null,{
                        status: 404,
                        message: 'User not found'
                    });
                }
            }]
        },
        (err, results) => {
            if(err){
                console.log('async auto callback :: err = ', err);
            }else{
                console.log('async auto callback :: results = ', results);
            }
        }
    );
}

const username = randString(10);
const password = randString(20);
login(username, password);