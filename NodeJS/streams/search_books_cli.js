const readline = require('readline');
const request = require('request');
const URL = 'http://gobooksonline.herokuapp.com/search';

const rl = readline.createInterface(process.stdin, process.stdout);

function requestBook (bookName) {
    return new Promise((resolve, reject) => {
        request.post(URL, {
            form: {
                queryString: bookName
            }
        }, (err, res, body) => {
            if (err) {
                reject(err);
            } else {
                resolve(body);
            }
        });
    });
}

rl.on('line', (line) => {
    console.log('Input line:', line);
    requestBook(line)
    .then((result) => {
        console.log('Search results:');
        console.log(result);
    })
    .catch((err) => {
        console.log('Error fetching results:', err);
    });
});

process.on('exit', () => {
    console.log('Exit');
});




