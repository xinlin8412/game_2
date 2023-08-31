#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ʼ��Ϸ����
void menu()
{
	printf(" -------------------------\n");
	printf("|  1.��ʼ��Ϸ 2.�˳���Ϸ  |\n");
	printf(" -------------------------\n");
}


//��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;
	//����-����߳���������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);

	//����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//���������C������ѭ��������C�������壬ֱ������C,����C��������������
		{
			break;
		}


		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//���������C������ѭ��
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

//��ʼ��Ϸ/�˳���Ϸ
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//����һ�ξͿ����ˣ�
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input) //�ж�input��1����0
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		defaule:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}