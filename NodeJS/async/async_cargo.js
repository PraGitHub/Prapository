const async = require('async');
const randString = require('./randString');

const numTasks = 100;
const payload = 4;

const taskCargo = async.cargo((tasks, callback) => {
    var tc = tasks.length;
    console.log('task function :: num tasks = ', tc);
    tasks.forEach((task) => {
        console.log(`Performing the task ${task.id}`);
        setTimeout((taskId) => {
            //delay to simulate the task
            console.log(`Task ${taskId} completed, calling callback`);
            tc--;
            if(tc == 0){
                callback();
            }
        }, 1000, task.id);
    });
}, payload)

var taskList = [];

for (let i = 1; i <= numTasks; i++) {
    taskList.push(randString(25));
}

taskList.forEach((task) => {
    setTimeout(() => {
        console.log(`Pushing task ${task}`);
        taskCargo.push({ id: task }, (err) => {
            if (err) {
                console.error(err);
            }
        });
    }, 100);
});


