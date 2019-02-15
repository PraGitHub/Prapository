var count = 0;
var fs = require('fs');

function stackOverflow(){
    count = count + 1;
    fs.writeFileSync("./results/node/stackOverflow.js.result.5",count);
    stackOverflow();
}

stackOverflow();