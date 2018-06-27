#include <iostream>
#include <vector>
using namespace std;

static int iXMain = 0;
static int iYMain = 0;

void nextMove(int player, vector <string> board){
    int iX = iXMain;
    int iY = iYMain;
    for(int i=iX;i<8;i++){
        for(int j=iY;j<8;j++){
            if(i+1<8 && j+1<8){
                if(board[i][j]==0&&(board[i+1][j]==1||board[i][j+1]==1)){
                    iXMain = i;
                    iYMain = j+1;
                    if(j==7){
                        iXMain = i+1;
                        iYMain = 0;
                    }
                    cout<<i<<" "<<j<<endl;
                    return;
                }
            }
            if(j==7){
                if(board[i][j]==1){
                    iXMain = i+1;
                    iYMain = 0;
                    cout<<i<<" "<<j<<endl;
                    return;
                }
            }
            if(board[i][j]==1){
                iXMain = i;
                iYMain = j+1;
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
}

int main(void) {

    int player;
    vector <string> board;

    //If player is 1, I'm the first player.
    //If player is 2, I'm the second player.
    cin >> player;

    //Read the board now. The board is a 8x8 array filled with 1 or 0.
    for(int i=0; i<8; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    nextMove(player,board);

    return 0;
}
