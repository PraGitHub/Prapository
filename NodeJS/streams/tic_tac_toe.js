const readline = require('readline');
const rl = readline.createInterface(process.stdin);

const EMPTY = ' ', P_1 = 'O', P_2 = 'X';

var board = new Array(9).fill(EMPTY);

var game_tracker = 1;

var player = true;

function initBoard () {
    board = new Array(9).fill(EMPTY);
    game_tracker = 1;
}

function printBoard () {
    var line = '|';
    for (let i in board) {
        line = `${line} ${board[i]} |`;
        if ((i+1) % 3 == 0) {
            console.log(line);
            line = '|';
        }
    }
}

function updateBoard (pos) {
    if (board[pos - 1] != EMPTY) {
        return false;
    }
    var state = P_2;
    if (player) {
        state = P_1;
    }
    board[pos - 1] = state;
    return true;
} 

function checkIfSame (i1, i2, i3) {
    // console.log(i1, i2, i3, board[i1], board[i2], board[i3]);
    // console.log(board[i1] != EMPTY);
    // console.log(board[i1] == board[i2] && board[i2] == board[i3]);
    if (board[i1] != EMPTY) {
        if (board[i1] == board[i2] && board[i2] == board[i3]) {
            return true;
        }
    }
    return false;
}

function checkGame () {
    if (game_tracker < 5) {
        return;
    }
    var winner = EMPTY;
    if (checkIfSame(0, 1, 2)) {
        winner = board[0];
    } else if(checkIfSame(3, 4, 5)) {
        winner = board[3];
    } else if(checkIfSame(6, 7, 8)) {
        winner = board[6];
    } else if(checkIfSame(0, 3, 6)) {
        winner = board[0];
    } else if(checkIfSame(1, 4, 7)) {
        winner = board[1];
    } else if(checkIfSame(2, 5, 8)) {
        winner = board[2];
    } else if(checkIfSame(0, 4, 8)) {
        winner = board[0];
    } else if(checkIfSame(2, 4, 6)) {
        winner = board[2];
    }
    if (winner != EMPTY) {
        console.log('=========GAME OVER=========');
        console.log(`=========PLAYER ${winner} Won!=========`)
        printBoard();
        initBoard();
        console.log('=========NEW GAME=========');
    }
    if (game_tracker > 9) {
        console.log('=========GAME OVER=========');
        printBoard();
        initBoard();
        console.log('=========NEW GAME=========');
        printBoard();
    }
}

rl.on('line', (position) => {
    if (position < 1 || position > 9) {
        console.log('Invalid Position');
        console.log('Please enter the position again');
        printBoard();
        return;
    }
    if (!updateBoard(position)){
        console.log('Position is already occupied');
        console.log('Please enter the position again');
        printBoard();
        return;
    }
    game_tracker++;
    player = !player;
    checkGame();
    printBoard();
});

process.on('exit', () =>  {
    console.log('Exit');
});

console.log('=========TIC TAC TOE=========');
printBoard();