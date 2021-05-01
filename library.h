//
// Created by NIamh on 16/04/2021.
//
#define boardsize 8
#ifndef ASSIGNMENT_2_LIBRARY_H
#define ASSIGNMENT_2_LIBRARY_H
void showboard(char board[boardsize][boardsize]);
void change (char board[boardsize][boardsize], int player, int *moverow, int *movecolumn);
int validmove(char board[boardsize][boardsize], int player,  int moverow, int movecolumn);
void flip(char board[boardsize][boardsize], int player,  int moverow, int movecolumn);
int validpass(char board[boardsize][boardsize], int player);
#endif //ASSIGNMENT_2_LIBRARY_H
