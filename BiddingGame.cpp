int calculate_bid(int player, int pos,int* first_moves, int* second_moves) {
    int iUpperHand = 0;
    int iP1 = 0;
    int iP2 = 0;
    int iSum1 = 0;
    int iSum2 = 0;
    int iThisMove = 0;
    for(int i=0;i<3;i++){
        iSum1 = iSum1 + first_moves[i];
        iSum2 = iSum2 + second_moves[i];
        if(first_moves[i]>second_moves[i]){
            iP1++;
        }
        if(first_moves[i]<second_moves[i]){
            iP2++;
        }
        
    }
    
    if(iP1>iP2){
        iUpperHand = 1;
    }
    if(iP1<iP2){
        iUpperHand = 2;
    }
    
    if(iUpperHand == player){
        return 8;
    }
    return 12;
}
