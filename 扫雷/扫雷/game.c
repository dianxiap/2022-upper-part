#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"
//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------ɨ��----------\n");
	//�����к�
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------ɨ��----------\n");
}
//������
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		//1. ��������±�
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		//2. ������
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
//����׵�λ��
void MarkMine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����������Ҫ���λ�õ�����->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)    //�жϸ������Ƿ�Ϸ�
		{
			if (board[x][y] == '*')        //�жϸ������Ƿ��Ų�
			{
				board[x][y] = '!';
				break;
			}
			else
			{
				printf("��λ�ò��ܱ���ǣ�����������!\n");
			}
		}
		else
		{
			printf("�����������������!\n");
		}
	}
}
//������Χ�׵�����
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] +
		mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0');
}

//��ȫ�ı�ըʽչ��

void boom_broad(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//�ж������Ƿ�Խ��
	if (x == 0 || y == 0 || x == ROWS - 1 || y == COLS - 1)
		return;
	//�ж��Ƿ��Ѿ����ų�
	if (show[x][y] != '*')
	{
		return;
	}
	int count = get_mine_count(mine, x, y);
	if (count > 0)
	{
		show[x][y] = count + '0';
		return;
	}
	//�ݹ���չ��ͼ
	else if (count == 0)
	{
		show[x][y] = '0';
		boom_broad(mine, show, x - 1, y);
		boom_broad(mine, show, x - 1, y - 1);
		boom_broad(mine, show, x, y - 1);
		boom_broad(mine, show, x + 1, y - 1);
		boom_broad(mine, show, x + 1, y);
		boom_broad(mine, show, x + 1, y + 1);
		boom_broad(mine, show, x, y + 1);
		boom_broad(mine, show, x - 1, y + 1);
	}
}

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	char ch;
	int sum = 0;
	while (win < (row * col - EASY_COUNT))
	{
		printf("������Ҫ�Ų������:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("�����걻�Ų����\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				boom_broad(mine, show, x, y);
				int n = get_mine_count(mine, x, y);
				show[x][y] = n + '0';
				DisplayBoard(show, ROW, COL);
				win++;
				while (1) {
					printf("��Ҫ����׵�λ��������y/Y,�����밴�����->");
					while ((ch = getchar()) != '\n');  //��������
					scanf("%c", &ch);
					if (ch == 'Y' || ch == 'y')
					{
						MarkMine(show, row, col);   //�����
						sum++;
						DisplayBoard(show, ROW, COL);
						printf("��ʣ%d����!\n", EASY_COUNT - sum);
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			printf("����Ƿ�����������\n");
		}
	
	}
	if (win == (row * col - EASY_COUNT))
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}
