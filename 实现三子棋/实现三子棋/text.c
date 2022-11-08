//test.c
#define _CRT_SECURE_NO_DEPRECATE  1
#include"game.h"

void menu()
{
	printf("******������*******\n");
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
	//����
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
		printf("���Ӯ\n");
	else if (ret == '#')
		printf("����Ӯ\n");
	else if (ret == 'Q')
		printf("ƽ��\n");

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}
	} while (input);
	return 0;
}