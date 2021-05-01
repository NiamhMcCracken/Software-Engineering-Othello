#define boardsize 8
//A function to print out the current board. It only takes in board
void showboard(char board[boardsize][boardsize]){
    //row and column variables are initialised along with a character array to label the columns
    int row = 0;
    int column = 0;
   char label [8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};


    printf("\n ");
    //the labels for each column are printed at the top of the board
    for(column = 0 ; column<boardsize ;column++) {
        printf("   %c", label[column]);
    }
        printf("\n");
    //the board is created using a *---* pattern for each row and column
    for(row = 0; row < boardsize; row++) {
        printf("  *");
        for (column = 0; column < boardsize; column++) {
            printf("---*");
        }
        //the appropriate row number is printed out at the start of each row
           printf("\n% d|", row+1);
        //the tiles are printed out onto the board (B/W/empty) and are separated by a |
        for(column = 0; column<boardsize; column++) {
            printf(" %c |", board[row][column]);
        }
        //when this is done for each column row is incremented and the process repeats on the next line
            printf("\n");
        }
//the bottom line of the board is printed out separately as it does not contain characters underneath
    printf("  *");
    for(column = 0 ; column<boardsize;column++) {
        printf("---*");
    }
        printf("\n");

}
