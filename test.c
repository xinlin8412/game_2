#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//开始游戏界面
void menu()
{
	printf(" -------------------------\n");
	printf("|  1.开始游戏 2.退出游戏  |\n");
	printf(" -------------------------\n");
}


//游戏的整个算法实现
void game()
{
	char ret = 0;
	//数组-存放走出的棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);

	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//如果不等于C就跳出循环，等于C继续下棋，直到等于C,等于C就是棋盘下满了
		{
			break;
		}


		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//如果不等于C就跳出循环
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

//开始游戏/退出游戏
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//生成一次就可以了，
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input) //判断input是1还是0
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		defaule:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}