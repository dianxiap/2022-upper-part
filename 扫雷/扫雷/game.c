#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"
//初始化雷盘
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
//打印雷盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------扫雷----------\n");
	//控制列号
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
	printf("---------扫雷----------\n");
}
//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		//1. 生成随机下标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		//2. 布置雷
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
//标记雷的位置
void MarkMine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入你想要标记位置的坐标->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)    //判断该坐标是否合法
		{
			if (board[x][y] == '*')        //判断该坐标是否被排查
			{
				board[x][y] = '!';
				break;
			}
			else
			{
				printf("该位置不能被标记，请重新输入!\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入!\n");
		}
	}
}
//计算周围雷的数量
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] +
		mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0');
}

//安全的爆炸式展开

void boom_broad(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	//判断坐标是否越界
	if (x == 0 || y == 0 || x == ROWS - 1 || y == COLS - 1)
		return;
	//判断是否已经被排除
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
	//递归拓展地图
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

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	char ch;
	int sum = 0;
	while (win < (row * col - EASY_COUNT))
	{
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标被排查过了\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
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
					printf("需要标记雷的位置请输入y/Y,否则请按任意键->");
					while ((ch = getchar()) != '\n');  //清理缓冲区
					scanf("%c", &ch);
					if (ch == 'Y' || ch == 'y')
					{
						MarkMine(show, row, col);   //标记雷
						sum++;
						DisplayBoard(show, ROW, COL);
						printf("还剩%d个雷!\n", EASY_COUNT - sum);
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
			printf("坐标非法，重新输入\n");
		}
	
	}
	if (win == (row * col - EASY_COUNT))
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}
