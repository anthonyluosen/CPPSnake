#pragma once
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <time.h>
#include <iostream>
#include <Windows.h>
#include <iostream>

#define H 22
#define W 33

class chessboard {
public:
    char board[H][W];
    int i, j, x1, y1;
    //chessboard();
    chessboard() {

        for (int i = 1; i <= H - 2; i++)
            for (int j = 1; j <= W - 2; j++)
                board[i][j] = ' ';
        for (int i = 0; i <= W - 1; i++)
            board[0][i] = board[H - 1][i] = '%';
        for (int i = 1; i <= H - 2; i++)
            board[i][0] = board[i][W - 1] = '%';
        food();
    }
    //chessboard();
    void food();
    void prt(int grade, int score, int gamespeed);


};

#endif
