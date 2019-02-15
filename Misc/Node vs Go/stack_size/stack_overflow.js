var count = 0;
var fs = require('fs');
function stackOverflow(){
    count = count + 1;
    fs.writeFileSync("stackOverflow.js.result",count);
    stackOverflow();
}

stackOverflow();