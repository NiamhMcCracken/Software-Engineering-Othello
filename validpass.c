//A function called when a player attempts to pass  that takes in the board and the current player and checks whether
//that their pass is valid, i.e that they have no valid moves. It calls the validmoves function as part of the function
int validpass(char board[boardsize][boardsize], int player){
    //valid is initialised to 1, a valid pass
int valid = 1;
int row = 0;
 int column = 0;
 //the function valid move is called for every blank square on the board
 //if a single one of these squares returns positive for validmove valid equals 0 and is returned
 //the pass fails and the user is prompted to enter a move
 //if the function validmove fails to return for any square valid 1 is returned, and the pass is deemed valid
    for (row = 0; row < boardsize; row++) {
        for (column = 0; column < boardsize; column++) {
            if(board[row][column]==' '){
          if( validmove(board, player, row, column)) {
              valid = 0;
              return valid;
          }
          }
        }
    }
    return valid;
}

