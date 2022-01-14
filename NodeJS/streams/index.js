const fs = require('fs');

const FILE_PATH = './sample.log';

const stream = fs.createReadStream(FILE_PATH);

var sizeKb = 0;

// stream.pipe(process.stdout);

stream.on('data', (chunk) => {
    var chunkSizeKb = chunk.toString().length / 1024;
    sizeKb += chunkSizeKb;
    console.log(`Chunk size: ${chunkSizeKb} kB`);
});

stream.on('end', () => {
    console.log(`Total size: ${sizeKb} kB`);
    stream.close();
});

stream.on('error', (err) => {
    console.error('Error while reading stream:', err.stack);
});
