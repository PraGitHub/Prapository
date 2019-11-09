const async = require('async');
const randString = require('./randString');

const numTasks = 10;
const concurrency = 1;
const numHpTasks = 2;
const taskExecTime = 10;
const hpTaskPushInterval = 20;

const taskQueue = async.queue((task, callback) => {
    console.log(`Performing the task ${task.id}`);
    setTimeout((taskId) => {
        //delay to simulate the task
        console.log(`Task ${taskId} completed, calling callback`);
        callback();
    }, taskExecTime, task.id);
}, concurrency);

taskQueue.drain = () => {
    console.log('All tasks are completed');
}

var taskList = [];

for(let i=1; i<=numTasks; i++){
    taskList.push(randString(25));
}

taskList.forEach((task) => {
    console.log(`Pushing task ${task}`);
    taskQueue.push({id: task}, (err) => {
        if(err){
            console.error(err);
        }
    });
});

var hpTaskPushedCount = 0;
const pushHpTask = () => {
    setTimeout(() => {
        var hpTask = `HighPriorityTask_${randString(10)}`;
        console.log(`Pushing high priority task ${hpTask}`);
        taskQueue.unshift({ id: hpTask }, (err) => {
            if (err) {
                console.error(err);
            }
        });
        hpTaskPushedCount++;
        if (hpTaskPushedCount >= numHpTasks) {
            return;
        }else{
            pushHpTask();
        }
    }, hpTaskPushInterval);
}

pushHpTask();

