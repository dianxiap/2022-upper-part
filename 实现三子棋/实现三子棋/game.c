//game.c
#define _CRT_SECURE_NO_DEPRECATE  1
#include"game.h"

//��ʼ������
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
//��ӡ����
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
//�������
void player_move(char board[ROW][COL], const int row, const int col)
{
	int x = 0;
	int y = 0;
	printf("�������:>\n");
	while (1)
	{
		printf("����������:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�������ѱ�ռ�ã�����������\n");
		}
		else
		{
			printf("�������̷�Χ������������\n");
		}
	}
}
//��������
void computer_move(char board[ROW][COL], const int row, const int col)
{
	printf("��������:>\n");
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
//�ж������Ƿ�����
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
//�ж�����״̬
char is_win(char board[ROW][COL], const int row, const int col)
{
	int i = 0;
	int j = 0;
	//ÿһ�и������Ƿ���ͬ
	for (i = 0; i < row; i++)
	{
		int flag = 1;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] != board[i][j + 1] || board[i][j] == ' ')
				flag = 0;
		}
		if (flag == 1)
			return board[i][0];//ֱ�ӷ������ӵ����ݾ�֪����˭Ӯ
	}
	//ÿһ�и������Ƿ���ͬ
	for (i = 0; i < col; i++)
	{
		int flag = 1;
		for (j = 0; j < row - 1; j++)
		{
			if (board[j][i] != board[j + 1][i] || board[j][i] == ' ')
				flag = 0;
		}
		if (flag == 1)
			return board[0][i];//ֱ�ӷ������ӵ����ݾ�֪����˭Ӯ
	}
	//���Խ��߸������Ƿ���ͬ
	i = 0;
	j = 0;
	while (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1])
	{
		i++;
		j++;
		if (i == row - 1 || j == col - 1)
			return board[0][0];//ֱ�ӷ������ӵ����ݾ�֪����˭Ӯ
	}
	//�ζԽ��߸������Ƿ���ͬ
	i = 0;
	j = 0;
	while (board[i][col - 1 - j] != ' ' && board[i][col - 1 - j] == board[i + 1][col - 2 - j])
	{
		i++;
		j++;
		if (i == row - 1 || j == col - 1)
			return board[0][col - 1];//ֱ�ӷ������ӵ����ݾ�֪����˭Ӯ
	}
	//�Ƿ�ƽ��
	if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'c';
}
