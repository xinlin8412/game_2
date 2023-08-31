#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//初始化都为空格
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	//打印棋盘的样式如下
	//   |   |   
	//---|---|---
	//   |   |   
	//---|---|---
	//   |   |
	//循环3次，每次打印
	//   |   |   
	//---|---|---  ，最后一次不打印竖杠和分割行
	int i = 0;
	int j = 0;
	//打印一行数据
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//打印空格，“ /c ”左右都加了空格，所有这里一次是3个空格，打一个竖杠
			if (j < col - 1)//最后一次不需要竖杠
			{
				printf("|");

			}
		}
		printf("\n");


		//打印分割行
		if (i < row - 1) //不打印最后一行分割行
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)  //让分割行中间带竖杠，并且最后一次不打印
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");
	while (1)
	{
		printf("请输入要下的坐标");
		scanf("%d%d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
			//判断是否为空坐标
			if (board[x - 1][y - 1] == ' ')//这里x-1,y-1的原因，因为用户输入的是1-3的数，而坐标是从0-2的，所有需要都减一，得到当前坐标
			{
				board[x - 1][y - 1] = '*';//如果为空坐标填入*号
				break;
			}
			else
			{
				printf("改坐标已被占用，请重新输入");
			}
		else
		{
			printf("你输入的坐标不合法，请重新输入");
		}

	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
	while (1)
	{
		x = rand() % row; //模上一个row,得到一个0到row的取值范围
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}

	}

}


//判断平局
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			if (board[i][j] == ' ') //判断当前棋盘是否还有空格，如果有证明还没下满，返回0
			{
				return 0; 
			}
		
	}
	return 1;
}


//判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//判断3行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//判断3列
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断是否平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';  //平局返回Q

	}
	return 'C';  //继续返回C
}
