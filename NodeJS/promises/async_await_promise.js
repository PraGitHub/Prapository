const error = false;

function start () {
    return new Promise((resolve, reject)=>{
        setTimeout(() => {
            console.log('Done!');
            if (!error) {
                resolve('Resolved.');
            } else {
                reject('Rejected');
            }
        }, 1000);
    });
}

// Ways to deal with promises

// 1. async + await
async function wrapper () {
    console.log('wrapper: Before await');
    const await_result = await start();
    console.log('wrapper: After await: await_result = ', await_result);
}

console.log('main: Before calling wrapper');

wrapper()
.catch((err)=>{
    console.error('Inside catch of wrapper: ', err);
});

console.log('main: After calling wrapper');

// 2. .then, .catch
start().then((result)=>{
    console.log(`Inside then: ${result}`);
}).catch((err)=>{
    console.error('Inside catch of start: ', err);
});

// 2. .then, .catch chain
start()
.then((result)=>{
    console.log(`Inside then: ${result}`);
    return `Cascaded: ${result}`;
})
.then((result) => {
    console.log(`Inside then: ${result}`);
    //return `Cascaded: ${result}`;
})
.catch((err)=>{
    console.error('Inside catch of start: ', err);
});

setTimeout(()=>{console.log('Ultimate timeout.')}, 5000);