#include "chessboard.h"



//chessboard::chessboard() {
//
//    for (int i = 1; i <= H - 2; i++)
//        for (int j = 1; j <= W - 2; j++)
//            board[i][j] = ' ';
//    for (int i = 0; i <= W - 1; i++)
//        board[0][i] = board[H - 1][i] = '%';
//    for (int i = 1; i <= H - 2; i++)
//        board[i][0] = board[i][W - 1] = '%';
//    food();
//}

void chessboard::food() {
    srand(time(nullptr));
    do
    {
         x1 = rand() % W - 2 + 1;
         y1 = rand() % H - 2 + 1;
    } 
    while (board[x1][y1] != ' ');
    board[x1][y1] = '$';
}

void chessboard::prt(int grade, int score, int gamespeed) {
    system("cls");
    std::cout << std::endl;
    for (i = 0; i < H; i++)
    {
        std::cout << "\t";
        for (j = 0; j < W; j++)
            std::cout << board[i][j] << ' ';
        if (i == 1)std::cout << "\tfood postion: X" << x1 << " Y"<< y1;
        if (i == 0)std::cout << "\tGrade:" << grade;
        if (i == 2) std::cout << "\tScore: " << score;
        if (i == 4) std::cout << "\tAutomatic forward";
        if (i == 5) std::cout << "\ttime interval:" << gamespeed << "ms";
        std::cout << std::endl;
    }
}
