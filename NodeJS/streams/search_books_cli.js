const readline = require('readline');
const request = require('request');
const URL = 'http://gobooksonline.herokuapp.com/search?query=';

const rl = readline.createInterface(process.stdin);

function getURL (param) {
    return `${URL}${encodeURIComponent(param)}`;
}

function requestBook (bookName) {
    return new Promise((resolve, reject) => {
        let url = getURL(bookName);
        request.get(url, (err, res, body) => {
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
    if (!line) {
        console.log('Search query cannot be null');
        console.log('Enter the search query below:');
        return;
    }
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



