const async = require('async');
const {exec} = require('child_process');

const command = 'tasklist';

async.waterfall([
    executeCommand = (callback) =>{
        exec(command, (err, stdout, stderr) => {
            if(err){
                callback(err, null);
            }else{
                var cmdResult = {};
                cmdResult.cmd = command;
                cmdResult.stdout = stdout;
                cmdResult.stderr = stderr;
                callback(null, cmdResult);
            }
        });
    },
    handleCommandResult = (cmdResult, callback) =>{
        var result = '';
        if(cmdResult){
            result = `
--------------------------------------------------------------------------------------------------
    Command: ${cmdResult.cmd || ''}
--------------------------------------------------------------------------------------------------
    STDOUT: ${cmdResult.stdout || ''}
--------------------------------------------------------------------------------------------------
    STDERR: ${cmdResult.stderr || ''}
--------------------------------------------------------------------------------------------------
            `;
        }
        callback(null, result);
    }
], 
(err, result) => {
    if(err){
        console.error(err);
    }else{
        console.log('result: ', result)
    }
}
);

