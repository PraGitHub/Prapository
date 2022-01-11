const fs = require('fs');
const readline = require('readline');

const FILE_PATH = './sample.log';

const instream = fs.createReadStream(FILE_PATH);

const rl = readline.createInterface(instream);

var output = {};

function insertLine (module, line) {
    if (output[module]) {
        output[module].count++;
        output[module].lines.push(line);
    } else {
        output[module] = {
            lines: [line],
            count: 1
        };
    }
}

rl.on('line', (line) => {
    if (!line) {
        return;
    }
    var module = line.substring(0, line.indexOf(': '));
    module = module.substring(module.lastIndexOf('.') + 1);
    insertLine(module, line);
});

process.on('exit', () => {
    console.log('Output:');
    console.log(output);
})
