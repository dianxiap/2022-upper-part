#pragma once
//game.h
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROW  3
#define COL 3

//初始化棋盘
void InitBoard(char board[ROW][COL], const int row, const int col);
//打印棋盘
void DisplayBoard(char board[ROW][COL], const int row, const int col);
//玩家下棋
void player_move(char board[ROW][COL], const int row, const int col);
//电脑下棋
void computer_move(char board[ROW][COL], const int row, const int col);
//判断胜负
char is_win(char board[ROW][COL], const int row, const int col);