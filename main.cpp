#define _CRT_SECURE_NO_WARNINGS
#pragma once
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
#include<corecrt.h>
// 包括 SDKDDKVer.h 将定义可用的最高版本的 Windows 平台。
// 如果要为以前的 Windows 平台生成应用程序，请包括 WinSDKVer.h，并将
// 将 _WIN32_WINNT 宏设置为要支持的平台，然后再包括 SDKDDKVer.h。
#include <SDKDDKVer.h>
//此处为#include<targetver.h>
#include <stdio.h>
#include <tchar.h>
//此处为#include<stdafx.h>
// TODO:  在此处引用程序需要的其他头文件
#include<atlimage.h> 
#include<stdio.h>
#include<graphics.h>   //图形界面库头文件
#include<math.h>       //计算圆形的轨迹坐标
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
//下面开始绘制中国象棋棋盘

void draw_line(int a);
void draw_add(int a);
void draw_add1(int a, int b);
void draw_add2(int a, int b);
void draw_add3(int a, int b);
void draw_chessboard(int a);
void draw_chessman(int a);
void draw_char(int a);
void draw_final(int a);
void judge(int a);
void mouse(int a);
void choice(int a);
void init(int a);
void update(int a);
void database(int a);
void judge_is_available(int a, int b);
int database1(int a, int b);

#define WND_WIDTH 1000
#define WND_HEIGHT 1000
#define PI 3.1415826535897932384626

int main(int agrc, char* agrv[])
{
	printf("wait a while");
	Sleep(1000);
	initgraph(WND_WIDTH, WND_HEIGHT);
	BeginBatchDraw();
	setbkcolor(BROWN);
	cleardevice();
	init(1);
	while (!_kbhit())
	{
		//update(1);
		EndBatchDraw();
	}
	return 0;
}

void mouse(int a)
{
	MOUSEMSG m;
	FlushMouseMsgBuffer();
	int i = 0;
	int j = 0;
	while (1)
	{
		//控制模板
		//下面为控制的一个实际的例子
		/******************************************************\
		while (MouseHit())
		{
			m = GetMouseMsg();
			if ((m.x >= 105 && m.x <= 282) && (m.y >= 423 && m.y <= 480))//管理员模式
			{
				setlinecolor(RED);
				rectangle(105, 423, 282, 480);
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					//n = 1;
					return;
				}
			}
			if (!((m.x >= 105 && m.x <= 282) && (m.y >= 423 && m.y <= 480)))//鼠标放在按钮变色
			{
				setlinecolor(WHITE);
				rectangle(105, 423, 282, 480);
			}
			if ((m.x >= 751 && m.x <= 929) && (m.y >= 425 && m.y <= 482))//用户模式
			{
				setlinecolor(RED);
				rectangle(751, 425, 929, 482);
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					//n = 2;
					return;
				}
			}
			if (!((m.x >= 751 && m.x <= 929) && (m.y >= 425 && m.y <= 482)))//鼠标放在按钮变色
			{
				setlinecolor(WHITE);
				rectangle(751, 425, 929, 482);
			}

		}
		\*******************************************************************/
		while (MouseHit())
		{
			m = GetMouseMsg();
			for (i = 0; i < 9; i++)
			{
				for (j = 0; j < 10; j++)
				{
					if ((m.x > (50 + 100 * i) && m.x < (100 * i - 50)) && (m.y > (100 * j)) && (m.y < 100 * j + 100))
					{
						judge_is_available(i + 1, j + 1);
					}
				}
			}
		}
	}
}

void init(int a)
{
	draw_line(1);
	draw_add(1);
	draw_chessboard(1);
	draw_chessman(1);
	draw_char(1);
}

void update(int a)
{
	//mouse(1);
	//judge(1);
	//choice(1);
	//mouse(1);
	//judge(1);
	//database(1);
}

void draw_line(int a)
{
	int i = 0;
	for (i = 0; i <= 9; i++)
	{
		setlinecolor(BLACK);
		line(100, 50 + 100 * i, 900, 50 + 100 * i);
	}
	line(100, 50, 100, 950);
	line(900, 50, 900, 950);
	for (i = 0; i < 7; i++)
	{
		line(200 + 100 * i, 50, 200 + 100 * i, 450);
	}
	for (i = 0; i < 7; i++)
	{
		line(200 + 100 * i, 550, 200 + 100 * i, 950);
	}
	line(400, 50, 600, 250);
	line(400, 250, 600, 50);
	line(400, 950, 600, 750);
	line(400, 750, 600, 950);
}

void draw_add1(int a, int b)
{
	setlinecolor(BLACK);
	line(a - 20, b - 10, a - 10, b - 10);
	line(a - 10, b - 20, a - 10, b - 10);
	line(a + 10, b - 10, a + 20, b - 10);
	line(a + 10, b - 10, a + 10, b - 20);
	line(a - 20, b + 10, a - 10, b + 10);
	line(a - 10, b + 10, a - 10, b + 20);
	line(a + 10, b + 10, a + 20, b + 10);
	line(a + 10, b + 10, a + 10, b + 20);
}

void draw_add2(int a, int b)
{
	setlinecolor(BLACK);
	line(a + 10, b - 10, a + 20, b - 10);
	line(a + 10, b - 10, a + 10, b - 20);
	line(a + 10, b + 10, a + 20, b + 10);
	line(a + 10, b + 10, a + 10, b + 20);
}

void draw_add3(int a, int b)
{
	setlinecolor(BLACK);
	line(a - 20, b - 10, a - 10, b - 10);
	line(a - 10, b - 20, a - 10, b - 10);
	line(a - 20, b + 10, a - 10, b + 10);
	line(a - 10, b + 10, a - 10, b + 20);
}

void draw_add(int a)
{
	draw_add1(200, 250);
	draw_add1(800, 250);
	draw_add1(300, 350);
	draw_add1(500, 350);
	draw_add1(700, 350);
	draw_add1(200, 750);
	draw_add1(800, 750);
	draw_add1(300, 650);
	draw_add1(500, 650);
	draw_add1(700, 650);
	draw_add2(100, 350);
	draw_add2(100, 650);
	draw_add3(900, 350);
	draw_add3(900, 650);
}

void draw_chessboard(int a)
{
	setfillcolor(RGB(192, 192, 192));
	fillcircle(100, 50, 50);
	fillcircle(200, 50, 50);
	fillcircle(300, 50, 50);
	fillcircle(400, 50, 50);
	fillcircle(500, 50, 50);
	fillcircle(600, 50, 50);
	fillcircle(700, 50, 50);
	fillcircle(800, 50, 50);
	fillcircle(900, 50, 50);
	fillcircle(200, 250, 50);
	fillcircle(800, 250, 50);
	fillcircle(100, 350, 50);
	fillcircle(300, 350, 50);
	fillcircle(500, 350, 50);
	fillcircle(700, 350, 50);
	fillcircle(900, 350, 50);
	//黑方准备完成
	fillcircle(100, 950, 50);
	fillcircle(200, 950, 50);
	fillcircle(300, 950, 50);
	fillcircle(400, 950, 50);
	fillcircle(500, 950, 50);
	fillcircle(600, 950, 50);
	fillcircle(700, 950, 50);
	fillcircle(800, 950, 50);
	fillcircle(900, 950, 50);
	fillcircle(200, 750, 50);
	fillcircle(800, 750, 50);
	fillcircle(100, 650, 50);
	fillcircle(300, 650, 50);
	fillcircle(500, 650, 50);
	fillcircle(700, 650, 50);
	fillcircle(900, 650, 50);
	//红方准备完成
}

void draw_chessman(int a)
{
	settextcolor(BLACK);
	setbkmode(0);
	settextstyle(40, 0, 0);
	outtextxy(80, 30, L'车');
	outtextxy(180, 30, L'马');
	outtextxy(280, 30, L'象');
	outtextxy(380, 30, L'士');
	outtextxy(480, 30, L'将');
	outtextxy(580, 30, L'士');
	outtextxy(680, 30, L'象');
	outtextxy(780, 30, L'马');
	outtextxy(880, 30, L'车');
	outtextxy(180, 230, L'炮');
	outtextxy(780, 230, L'炮');
	outtextxy(80, 330, L'卒');
	outtextxy(280, 330, L'卒');
	outtextxy(480, 330, L'卒');
	outtextxy(680, 330, L'卒');
	outtextxy(880, 330, L'卒');
	settextcolor(RED);
	outtextxy(80, 930, L'车');
	outtextxy(180, 930, L'马');
	outtextxy(280, 930, L'象');
	outtextxy(380, 930, L'士');
	outtextxy(480, 930, L'帅');
	outtextxy(580, 930, L'士');
	outtextxy(680, 930, L'象');
	outtextxy(780, 930, L'马');
	outtextxy(880, 930, L'车');
	outtextxy(180, 730, L'炮');
	outtextxy(780, 730, L'炮');
	outtextxy(80, 630, L'兵');
	outtextxy(280, 630, L'兵');
	outtextxy(480, 630, L'兵');
	outtextxy(680, 630, L'兵');
	outtextxy(880, 630, L'兵');
}

void draw_char(int a)
{
	settextcolor(BLACK);
	setbkmode(0);
	outtextxy(230, 470, L'楚');
	outtextxy(330, 470, L'河');
	outtextxy(630, 470, L'汉');
	outtextxy(730, 470, L'界');
}

void database(int a)
{

}

int database1(int a, int b)
{
	int aa[9][10] = { 0 };
	//定义一个虚拟棋盘
	//即将开始处理棋盘信息
	//第一个数字1、2代表是红方还是黑方
	//红为1，黑为2
	//第二个数字1，2，3，4，5，6，7，8，9，0代表车，马，象，士，将（帅），炮，卒（兵）
	aa[0][0] = 21;
	aa[1][0] = 22;
	aa[2][0] = 23;
	aa[3][0] = 24;
	aa[4][0] = 25;
	aa[5][0] = 24;
	aa[6][0] = 23;
	aa[7][0] = 22;
	aa[8][0] = 21;
	aa[1][2] = 26;
	aa[7][2] = 26;
	aa[0][4] = 27;
	aa[2][4] = 27;
	aa[4][4] = 27;
	aa[6][4] = 27;
	aa[8][4] = 27;
	aa[0][6] = 17;
	aa[2][6] = 17;
	aa[4][6] = 17;
	aa[6][6] = 17;
	aa[8][6] = 17;
	aa[1][7] = 16;
	aa[7][7] = 16;
	aa[0][9] = 11;
	aa[1][9] = 12;
	aa[2][9] = 13;
	aa[3][9] = 14;
	aa[4][9] = 15;
	aa[5][9] = 14;
	aa[6][9] = 13;
	aa[7][9] = 12;
	aa[8][9] = 11;
	return aa[a-1][b-1];
}
