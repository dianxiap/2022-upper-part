#pragma once
//game.h
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROW  3
#define COL 3

//��ʼ������
void InitBoard(char board[ROW][COL], const int row, const int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL], const int row, const int col);
//�������
void player_move(char board[ROW][COL], const int row, const int col);
//��������
void computer_move(char board[ROW][COL], const int row, const int col);
//�ж�ʤ��
char is_win(char board[ROW][COL], const int row, const int col);