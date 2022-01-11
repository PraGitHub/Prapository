const readline = require('readline');

const rl = readline.createInterface(process.stdin, process.stdout);

rl.on('line', (line) => {
    console.log('Input line:', line);
});

process.on('exit', () => {
    console.log('Exit');
});