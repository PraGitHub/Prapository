const async = require('async');
const randString = require('./randString');

const numTasks = 100000;
const concurrency = 1;

const taskQueue = async.queue((task, callback) => {
    const startTime = new Date().getTime();
    //console.log(`Performing the task ${task.id}`);
    for(let i=1; i<=100; i++){
        var str = randString(100);
    }
    const percentageDone = 100 * (numTasks - taskQueue.length()) / numTasks;
    if(percentageDone % 10 == 0){
        console.log(`${percentageDone}% done`);
    }
    const endTime = new Date().getTime();
    const timeTaken = endTime - startTime;
    //console.log(`Task ${task.id} completed, took ${timeTaken} msec, calling callback`);
    //console.log(`taskQueue.length = ${taskQueue.length()}`);
    callback();
}, concurrency);

taskQueue.drain(() => {
    console.log('All tasks are completed');
    console.log('Exiting...');
    process.exit(0);
});

var taskList = [];

for(let i=1; i<=numTasks; i++){
    taskList.push(randString(25));
}

taskList.forEach((task) => {
    //console.log(`Pushing task ${task}`);
    taskQueue.push({id: task}, (err) => {
        if(err){
            console.error(err);
        }
    });
});