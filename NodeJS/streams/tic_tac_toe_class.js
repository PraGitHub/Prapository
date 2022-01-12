const readline = require('readline');
const rl = readline.createInterface(process.stdin);

class TicTacToe {
    constructor () {
        console.log('=========TIC TAC TOE=========');
        this._init();
    }

    _init () {
        this.empty = ' ';
        this.player_1 = 'O';
        this.player_2 = 'X';
        this.board = new Array(9).fill(this.empty);
        this.tracker = 1;
        this.player = true;
        console.log('=========NEW GAME=========');
        this._print();
    }

    _print () {
        let line = '|';
        for (let i in this.board) {
            line = `${line} ${this.board[i]} |`;
            if ((i+1) % 3 == 0) {
                console.log(line);
                line = '|';
            }
        }
    }

    _update (pos) {
        if (this.board[pos - 1] != this.empty) {
            return false;
        }
        this.board[pos - 1] = this.player_2;
        if (this.player) {
            this.board[pos - 1] = this.player_1;
        }
        return true;
    }

    _areSame (i1, i2, i3) {
        if (this.board[i1] != this.empty) {
            if (this.board[i1] == this.board[i2] &&  
                this.board[i2] == this.board[i3]
                ) {
                return true;
            }
        }
        return false;
    }

    _checkGame () {
        if (this.tracker < 5) {
            return this._print();
        }
        var winner = this.empty;
        if (this._areSame(0, 1, 2)) {
            winner = this.board[0];
        } else if(this._areSame(3, 4, 5)) {
            winner = this.board[3];
        } else if(this._areSame(6, 7, 8)) {
            winner = this.board[6];
        } else if(this._areSame(0, 3, 6)) {
            winner = this.board[0];
        } else if(this._areSame(1, 4, 7)) {
            winner = this.board[1];
        } else if(this._areSame(2, 5, 8)) {
            winner = this.board[2];
        } else if(this._areSame(0, 4, 8)) {
            winner = this.board[0];
        } else if(this._areSame(2, 4, 6)) {
            winner = this.board[2];
        }
        if (winner != this.empty) {
            console.log('=========GAME OVER=========');
            console.log(`=========PLAYER ${winner} Won!=========`)
            this._print();
            return this._init();
        }
        if (this.tracker > 9) {
            console.log('=========GAME OVER=========');
            this._print();
            return this._init();
        }
        return this._print();
    }

    start () {
        rl.on('line', function (position) {
            if (position < 1 || position > 9) {
                console.log('Invalid Position');
                console.log('Please enter the position again');
                this._print();
                return;
            }
            if (!this._update(position)){
                console.log('Position is already occupied');
                console.log('Please enter the position again');
                this._print();
                return;
            }
            this.tracker++;
            this.player = !this.player;
            this._checkGame();
        }.bind(this));
    }
};

let game = new TicTacToe();
game.start();