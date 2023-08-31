
#define ROW 3  //棋盘的行
#define COL 3  //棋盘的列
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//初始化棋盘函数
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢
//告诉我们4种状态
//1.玩家赢，返回‘*’
//2.电脑赢。返回‘#’
//3.平局，返回‘Q’
//4.继续，返回‘C’
char IsWin(char board[ROW][COL], int row, int col);

//判断平局
int IsFull(char board[ROW][COL], int row, int col);