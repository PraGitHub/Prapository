const readline = require('readline');
const request = require('request');
const URL = 'http://gobooksonline.herokuapp.com/search';

const rl = readline.createInterface(process.stdin);

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
        console.log('Enter the search query below:');
    })
    .catch((err) => {
        console.log('Error fetching results:', err);
        console.log('Enter the search query below:');
    });
});

process.on('exit', () => {
    console.log('Exit');
});

console.log('Enter the search query below:');



