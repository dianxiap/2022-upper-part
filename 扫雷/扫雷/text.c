#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("************************************\n");
	printf("********      1. play      *********\n");
	printf("********      0. exit      *********\n");
	printf("************************************\n");
}

void game()
{
	//1. 需要存放布置好的雷的信息，存放排查出的雷的信息，我们需要2个二维数组
	//2. 排查坐标的时候，为了防止坐标越界，我们给数组的行增加2行，列增加了2列
	char mine[ROWS][COLS] = { 0 };//布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//排查出的雷的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);
}

int main()
{

	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择!\n");
			break;
		}
	} while (input);

	return 0;
}


 
