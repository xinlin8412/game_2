#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//��ʼ����Ϊ�ո�
		}
	}
}

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	//��ӡ���̵���ʽ����
	//   |   |   
	//---|---|---
	//   |   |   
	//---|---|---
	//   |   |
	//ѭ��3�Σ�ÿ�δ�ӡ
	//   |   |   
	//---|---|---  �����һ�β���ӡ���ܺͷָ���
	int i = 0;
	int j = 0;
	//��ӡһ������
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//��ӡ�ո񣬡� /c �����Ҷ����˿ո���������һ����3���ո񣬴�һ������
			if (j < col - 1)//���һ�β���Ҫ����
			{
				printf("|");

			}
		}
		printf("\n");


		//��ӡ�ָ���
		if (i < row - 1) //����ӡ���һ�зָ���
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)  //�÷ָ����м�����ܣ��������һ�β���ӡ
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�>\n");
	while (1)
	{
		printf("������Ҫ�µ�����");
		scanf("%d%d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
			//�ж��Ƿ�Ϊ������
			if (board[x - 1][y - 1] == ' ')//����x-1,y-1��ԭ����Ϊ�û��������1-3�������������Ǵ�0-2�ģ�������Ҫ����һ���õ���ǰ����
			{
				board[x - 1][y - 1] = '*';//���Ϊ����������*��
				break;
			}
			else
			{
				printf("�������ѱ�ռ�ã�����������");
			}
		else
		{
			printf("����������겻�Ϸ�������������");
		}

	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>\n");
	while (1)
	{
		x = rand() % row; //ģ��һ��row,�õ�һ��0��row��ȡֵ��Χ
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}

	}

}


//�ж�ƽ��
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			if (board[i][j] == ' ') //�жϵ�ǰ�����Ƿ��пո������֤����û����������0
			{
				return 0; 
			}
		
	}
	return 1;
}


//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//�ж�3��
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//�ж�3��
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';  //ƽ�ַ���Q

	}
	return 'C';  //��������C
}
