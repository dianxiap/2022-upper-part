//game.c
#define _CRT_SECURE_NO_DEPRECATE  1
#include"game.h"

//初始化棋盘
void InitBoard(char board[ROW][COL], const int row, const int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void DisplayBoard(char board[ROW][COL], const int row, const int col)
{
	/*for (int i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if(i<row-1)
			printf("---|---|---\n");
	}*/
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
//玩家下棋
void player_move(char board[ROW][COL], const int row, const int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋:>\n");
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标已被占用，请重新输入\n");
		}
		else
		{
			printf("超出棋盘范围，请重新输入\n");
		}
	}
}
//电脑下棋
void computer_move(char board[ROW][COL], const int row, const int col)
{
	printf("电脑下棋:>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//判断棋盘是否下满
static int is_full(char board[ROW][COL], const int row, const int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//判断棋盘状态
char is_win(char board[ROW][COL], const int row, const int col)
{
	int i = 0;
	int j = 0;
	//每一行各棋子是否相同
	for (i = 0; i < row; i++)
	{
		int flag = 1;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] != board[i][j + 1] || board[i][j] == ' ')
				flag = 0;
		}
		if (flag == 1)
			return board[i][0];//直接返回棋子的内容就知道是谁赢
	}
	//每一列各棋子是否相同
	for (i = 0; i < col; i++)
	{
		int flag = 1;
		for (j = 0; j < row - 1; j++)
		{
			if (board[j][i] != board[j + 1][i] || board[j][i] == ' ')
				flag = 0;
		}
		if (flag == 1)
			return board[0][i];//直接返回棋子的内容就知道是谁赢
	}
	//主对角线各棋子是否相同
	i = 0;
	j = 0;
	while (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1])
	{
		i++;
		j++;
		if (i == row - 1 || j == col - 1)
			return board[0][0];//直接返回棋子的内容就知道是谁赢
	}
	//次对角线个棋子是否相同
	i = 0;
	j = 0;
	while (board[i][col - 1 - j] != ' ' && board[i][col - 1 - j] == board[i + 1][col - 2 - j])
	{
		i++;
		j++;
		if (i == row - 1 || j == col - 1)
			return board[0][col - 1];//直接返回棋子的内容就知道是谁赢
	}
	//是否平局
	if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'c';
}
