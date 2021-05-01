//Software Engineering 1, Assignment 2
//Author:Niamh McCracken
//I include the relavant libraries along with all four of my functions.
//I initialise the boardsize to 8
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<ctype.h>
#include <time.h>
#include <string.h>
#include "library.h"
#include "board.c"
#include "validmove.c"
#include "flip.c"
#include "validpass.c"
#define boardsize 8
//showboard takes in the board and prints it out to the screen
//validmove checks whether an entered move is valid or not by passing the move and current player. It returns an integer
//flip flips the counters after a valid move
//validpass is called when a player attempts to pass. It checks to make sure the player doesn't have any remaining valid moves. It returns an integer
void showboard(char board[boardsize][boardsize]);
int validmove(char board[boardsize][boardsize], int player,  int moverow, int movecolumn);
void flip(char board[boardsize][boardsize], int player,  int moverow, int movecolumn);
int validpass(char board[boardsize][boardsize], int player);


int main (void) {
    /*players are swapped between by the integer player, which is first set to 1. p1 and p2 are strings
     * for users to enter their names, with char winner being used to print the winners out to a file othello.txt
     * the board is a 2d array of size boardsize. Player inputs their move in the form of movec moved. these are then
     * converted into integers with array notation e.g a1 becomes [0][0] and placed in moverow and movecolumn
     * row and column are used to construct the board
     * separate integers hold the score for each player.
     * boolean variables pass1 and pass2 exist so the game ends after both players pass with bool currentpass stopping the program from calling validmove function on a pass
     * validentry checks whether or not what the user entered is valid (move or pass)
     * fPtr is a pointer to the file othello-results.txt*/
    int player = 1;
    char p1[10];
    char p2[10];
    char winner[20] = "It is a tie, nobody";
    char board[boardsize][boardsize];
    char movec;
    int moved;
    int moverow = 0;
    int movecolumn = 0;
    int row = 0;
    int column = 0;
    int p1score = 0;
    int p2score = 0;
    int colour;
    bool pass1 = false;
    bool pass2 = false;
    bool currentpass = false;
    int validentry = 0;
    FILE *fPtr;
    /*the two players enter their names and the board is cleared and initialised*/
    printf("Player1, please enter your name:\n");
    scanf("%s", p1);
    printf("\nPlayer2, please enter your name:\n");
    scanf("%s", p2);
    printf("\n%s will play B, %s will play W\n", p1, p2);
    for (row = 0; row < boardsize; row++) {
        for (column = 0; column < boardsize; column++) {
            board[row][column] = ' ';
        }
    }
    board[boardsize / 2 - 1][boardsize / 2 - 1] = 'W';
    board[boardsize / 2][boardsize / 2] = 'W';
    board[boardsize / 2 - 1][boardsize / 2] = 'B';
    board[boardsize / 2][boardsize / 2 - 1] = 'B';
    /*the newly initialised board is printed with the showboard function*/
    showboard(board);

    //The gameplay loop consists of two do while loops. the inner loop loops until the player enters a valid move
    //or valid pass while the outer loop loops until all squares on the board are filled or both players pass
    do{
        do{
            //current pass is set to false and valid entry set to 0
            currentpass = false;
            validentry=0;
            if(player==1){
                printf("%s, ",p1);
            }
            else{
                printf("%s, ", p2);
            }
            //the user is prompted to enter a move which is saved in the movec moved variables
            printf("please enter a valid move in the format (a-h)(1-8) or p(1-8) to pass ");
            scanf(" %c%d", &movec, &moved);
            //if the movec entered is equal to p validpass is called, with the current board and player
            //if the pass is valid validentry1 is equal to 0, which breaks the player out of the inner do while loop
            //and the boolean pass1 or pass2 is equal to true. The player is then swapped
            if(movec=='p'){
               if(validpass(board,player)) {
                   validentry = 1;
                   currentpass = true;
                   if (player == 1) {
                       pass1 = true;
                       printf("%s passed.\n", p1);
                       player = 2;
                   } else {
                       pass2 = true;
                       printf("%s passed.\n", p2);
                       player = 1;
                   }
               }
               //If validpass doesnt return 1 the player is prompted to enter a move
                if(validentry!=1){
                    printf("Pass not valid. Please enter a move\n");
                }
            }
            //If the player doesn't pass and instead enters a move, movec is comverted to an integer by subtracting
            //the ascii code of a from the character. It is then stored in movecolumn while moved-1 is stored into moverow
            else {
                movecolumn = (movec) - 'a';
                moverow = moved - 1;
            //if either the row or column is outside the board the player is prompted to re-enter
                if ((moverow < 0) || (moverow >= boardsize) || (movecolumn < 0) || (movecolumn >= boardsize)) {
                    validentry = 0;
                    printf("Move is outside the board. Please re-enter a move\n");
                } else {
                    //the validmove function is callled, passing the board, player and the moverow,movecolmumn
                    //if it doesn't return 1 the player is prompted to enter another move
                    validentry = validmove(board,player, moverow, movecolumn);
                    if(validentry!=1){
                        printf("Move not valid. Please enter another move\n");
                    }
                    else{
                        //if the move is valid the appropriate black or white disc is placed on the specified square
                        if (player == 1) {
                            colour = 'B';
                        } else {
                            colour = 'W';
                        }
                        board[moverow][movecolumn] = colour;
                    }
                }
            }
        }while(validentry !=1);
        //if the player made a valid move thats not a pass the flip function is called, passing the same parameters as the validmove function
        if(!currentpass) {
            flip(board, player, moverow, movecolumn);
            //the board is shown, both pass variables are reinitialised back to false and the players are switched
            showboard(board);
            pass1 = false;
            pass2 = false;
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }

           //the score for each player is calculated by looking through each space on the board and
           //counting the number of Bs and Ws using two for loops
            p1score = 0;
            for (row = 0; row < boardsize; row++) {
                for (column = 0; column < boardsize; column++) {
                    if (board[row][column] == 'B') {
                        p1score++;
                    }
                }
            }
            p2score = 0;
            for (row = 0; row < boardsize; row++) {
                for (column = 0; column < boardsize; column++) {
                    if (board[row][column] == 'W') {
                        p2score++;
                    }
                }
            }
            //the player's names and scores are printed after every move
            printf("%s's score:%d\n", p1, p1score);
            printf("%s's score:%d\n", p2, p2score);

        }

    }while((p1score+p2score)!=boardsize*boardsize && !(pass1&pass2));

    //once the game is over the scores are compared to find the winner or to see if theres a tie. if p1 or p2 wins
    //their name gets copied into the winner variable to be writ into the othello-results.txt file while
    //the variable remains unchanged if its a tie
    if(p1score>p2score){
        printf("%s wins!\n", p1);
        strcpy(winner, p1);
    }
    else if(p2score>p1score){
        printf("%s wins!\n",p2);
        strcpy(winner, p2);
    }
    else if(p1score==p2score){
        printf("The game is a tie\n");
    }
    //the exact date and time is calculated using time(&t) and printed out
    time_t t;
    time(&t);
    printf("This game was played at %s\n", ctime(&t));
    //the program attempts to open/create the file othello-results.txt.
    if ((fPtr = fopen("othello-results.txt", "w")) == NULL ) {
        puts("File could not be opened.");
    }
    //the winner, scores and time of the game are printed out to the text file
    fprintf(fPtr,"%s wins\n",winner);
    fprintf(fPtr,"%s scored %d and %s scored %d\n",p1,p1score,p2,p2score);
    fprintf(fPtr,"The game was played at %s\n", ctime(&t));
    fclose (fPtr);
}



