#include "Snake.h"
#include <conio.h> // for _kbhit() and _getch()
#include <algorithm> // 这是使用 std::max 所必需的




void snake::move()
{
     while(1)
     {
         timeover = 1;
         start = clock();
         while((timeover=(clock()-start<=gamespeed))&&!_kbhit());
         if(timeover)
         {
             _getch();
             direction = _getch();
         }
         switch(direction)
         {
         case 72: x= BodyPostion[0][head]-1; y= BodyPostion[1][head];break;
         case 80: x= BodyPostion[0][head]+1; y= BodyPostion[1][head];break;
         case 75: x= BodyPostion[0][head]; y= BodyPostion[1][head]-1;break;
         case 77: x= BodyPostion[0][head]; y= BodyPostion[1][head]+1;break;
         }
         if(x==0 || x==21 ||y==0 || y==21)
         {
             std::cout << "\tGame over!" << std::endl;break;
         }
         if(board[x][y]!=' '&&!(x==x1&&y==y1))

         {
             std::cout << "\tGame over!" << std::endl;break;
         }
         if(x==x1 && y==y1)
         {
             length ++;
             score=score+100;
             if(length>=8)
             {
                 length -= 8;
                 grade ++;
                 if(gamespeed>=200)
                     gamespeed = 550 - grade * 50;
             }
             board[x][y]= '@';
             board[BodyPostion[0][head]][BodyPostion[1][head]] = '*';
             head = (head+1)%100;
             BodyPostion[0][head] = x;
             BodyPostion[1][head] = y;
             food();
             prt(grade,score,gamespeed);
         }
         else
         {
             board[BodyPostion[0][tail]][BodyPostion[1][tail]]=' ';
             tail=(tail+1)%100;
             board[BodyPostion[0][head]][BodyPostion[1][head]]='*';
             head=(head+1)%100;
             BodyPostion[0][head]=x;
             BodyPostion[1][head]=y;
             board[BodyPostion[0][head]][BodyPostion[1][head]]='@';
             prt(grade,score,gamespeed);
         }
     }
 }