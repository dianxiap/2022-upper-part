//test.c
#define _CRT_SECURE_NO_DEPRECATE  1
#include"game.h"

void menu()
{
	printf("******三子棋*******\n");
	printf("*******************\n");
	printf("******1.start******\n");
	printf("******0.exit ******\n");
	printf("*******************\n");
	printf("*******************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = is_win(board, ROW, COL);
		if (ret != 'c')
			break;

		computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = is_win(board, ROW, COL);
		if (ret != 'c')
			break;

	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else if (ret == 'Q')
		printf("平局\n");

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
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}