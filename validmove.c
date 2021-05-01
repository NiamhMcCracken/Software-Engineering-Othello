// A function to check if an entered move is valid
int validmove(char board[boardsize][boardsize], int player,  int moverow, int movecolumn){
    //x and y are the row and column positions of the tiles the program is searching for
    //dirrow and dircolumn are the direction the program goes to look for opponent tiles
    //opponent is the opponent's colour while current is the current player's colout
        int x = 0;
        int y = 0;
        int dirrow = 0;
        int dircolumn = 0;
        int count = 0;
        int k = 0;
        int valid = 0;
        char opponent;
        char current;

    //opponent and current are initialised to B or W depending on the current player
        if (player == 1) {
            opponent = 'W';
            current = 'B';
        } else {
            opponent = 'B';
            current = 'W';
        }
    //the for loop searches in the eight directions around the specified square by using dirrow and dircolumn
    //the direction 0 0 is not searched because it is the moverow movecolumn square
        for (dirrow = -1; dirrow <= 1; dirrow++) {
            for (dircolumn = -1; dircolumn <= 1; dircolumn++) {
                if (dirrow == 0 && dircolumn == 0) {
                    dirrow = 0;
                } else {
                    //the program searches in whatever direction specified by dirrow and dircolumn as long as it stays on
                    //the board
                    if (moverow + dirrow >= 0 && moverow + dirrow < boardsize && movecolumn + dircolumn >= 0 &&
                        movecolumn + dircolumn < boardsize) {
                        //if it finds an opponent disc count becomes 1 and the do while loop is entered
                        if (board[moverow + dirrow][movecolumn + dircolumn] == opponent) {
                            x = moverow + dirrow;
                            y = movecolumn + dircolumn;
                            count = 1;
                            //it loops while the tile its looking at is either black/white (not blank) and on the board
                            do {
                                //x and y are increased as they continue down the direction specified by dirrow and dircolumn
                                x = x + dirrow;
                                y = y + dircolumn;
                                if (x < boardsize && x >= 0 && y >= 0 && y < boardsize) {
                                    if (board[x][y] != ' ') {
                                        //count is incremented everytime a flippable opponent tile is discovered
                                        if (board[x][y] == opponent) {
                                            count = count + 1;
                                        }
                                        //when a tile belonging to the current player is found we can assume the move is valid, and return 1
                                        if (board[x][y] == current) {
                                           valid = 1;
                                            return valid;
                                        }
                                    }
                                }
                            } while (((board[x + dirrow][y + dircolumn] == 'B')||(board[x + dirrow][y + dircolumn] == 'W')) && ((x + dirrow) < boardsize) &&
                                     ((y + dircolumn) < boardsize));
                        }
                    }
                }
            }
        }
        return valid;
    }
