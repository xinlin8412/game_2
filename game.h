
#define ROW 3  //���̵���
#define COL 3  //���̵���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��ʼ�����̺���
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
//��������4��״̬
//1.���Ӯ�����ء�*��
//2.����Ӯ�����ء�#��
//3.ƽ�֣����ء�Q��
//4.���������ء�C��
char IsWin(char board[ROW][COL], int row, int col);

//�ж�ƽ��
int IsFull(char board[ROW][COL], int row, int col);