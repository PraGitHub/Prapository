var output = {};

function addToOutput (key, value) {
    if (output[key]) {
        output[key].push(value);
    } else {
        output[key] = [value];
    }
};

function withVar () {
    for (var i = 1; i <= 5; i++) {
        setTimeout(() => {
            addToOutput('withVar', i);
        }, i * 100);
    }
}

function withLet () {
    for (let i = 1; i <= 5; i++) {
        setTimeout(() => {
            addToOutput('withLet', i);
        }, i * 100);
    }
}

function withPassIAsArgToSetTimeout () {
    for (var i = 1; i <= 5; i++) {
        setTimeout((i) => {
            addToOutput('withPassIAsArgToSetTimeout', i);
        }, i * 100, i);
    }
}

function withClosure () {
    for (var i = 1; i <= 5; i++) {
        function wrapper (i) {
            setTimeout(() => {
                addToOutput('withClosure', i);
            }, i * 100);
        }
        wrapper(i);
    }
}

withVar();
withLet();
withPassIAsArgToSetTimeout();
withClosure();

process.on('exit', () => {
    console.log('Exit handler: output =>');
    console.log(output);
});
