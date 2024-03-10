#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include "chessboard.h"

class snake :public chessboard
{
public:
	int BodyPostion[2][100];
	long start;
	int length;
	int head, tail, grade, gamespeed, score, timeover, x,y;
	char direction;
	//snake();
	snake() :score(0), head(3), tail(0), grade(0), length(4), gamespeed(500), direction(77)
	{
		std::cout << "\n\n\t snake game is above to begine!!" << std::endl;
		int i = 3;
		for (i; i > 0; i--)
		{
			start = clock();
			while (clock() - start <= 1000);
			system("cls");
			if (i > 0)
				std::cout << "\n\n\t Couting down " << i << std::endl;
		}
		for (int i = 1; i < 4; i++)
			board[1][i] = '=';
		board[1][4] = '>';
		for (int i = 0; i < 4; i++)
		{
			BodyPostion[0][i] = 1;
			BodyPostion[1][i] = i + 1;
		}
	}
	void move();
};


#endif 
