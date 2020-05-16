// game of Amazons.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <fstream>
using namespace std;

int game = 0;

const int Qblack = 1, Arrow = 2, Qwhite = 3, Blank = 0, Gsize = 8, itemsize = 60, Dsize = 8, SPAN = 4;
const int Blackloses = -3, Whiteloses = -2;
const int RADIUS = itemsize / 2 - SPAN;
const int UpperLeft = 0;
const int currBotColor = 1;
const int menuButtonSize = 60;
const int menuLoc = 700;
const int grid_white = -1;
const int grid_black = 1;
int turn = 0;
int gameresult;
double K = 0.2;
int Q_white[Gsize][Gsize] = { 0 };
int Q_black[Gsize][Gsize] = { 0 };
int flg = 0, flag = 0, flagstart = 0;
double v(int);
IMAGE white, black, arrow, cundang, save, load, leave, start, bckgpic, title;

int Gridinfo[Gsize][Gsize] = { 0 };		//每个棋子的情况
int go = Qwhite;			//初始白棋先走
int Direction[2][Dsize] = { -1,-1,0,1,1,1,0,-1,0,1,1,1,0,-1,-1,-1 };		//八个移动方向
int visK_B[Gsize][Gsize] = { 0 };            //用来记录各自的queen move 和 king move
int visQ_B[Gsize][Gsize] = { 0 };
int visK_W[Gsize][Gsize] = { 0 };            //用来记录各自的queen move 和 king move
int visQ_W[Gsize][Gsize] = { 0 };
int Kwhite[Gsize][Gsize] = { 0 };
int mobility[Gsize][Gsize] = { 0 };
int Kblack[Gsize][Gsize] = { 0 };
int a[Gsize][Gsize] = { 0 }; //模拟棋盘
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int startX, startY, resultX, resultY, obstacleX, obstacleY;


typedef struct position
{
	int x;
	int y;
	int s;
}Select_position;
Select_position whites_choice = { -1, -1 };
typedef struct route
{
	Select_position start;
	Select_position end;
	Select_position arrow;
}Select_route;
void Q_move_W(position pre);
void K_move_W(position pre);
void Q_move_B(position pre);
void K_move_B(position pre);
void getValue();

void loadImages()
{
	loadimage(&bckgpic, _T("bckgd.jpg"), 800, 600, FALSE);
	loadimage(&title, _T("title.jpg"), 500, 80, FALSE);
	loadimage(&black, _T("black.jpg"), RADIUS * 2 + SPAN / 2, RADIUS * 2 + SPAN / 2, FALSE);
	loadimage(&white, _T("white.jpg"), RADIUS * 2 + SPAN / 2, RADIUS * 2 + SPAN / 2, FALSE);
	loadimage(&arrow, _T("arrow.jpg"), RADIUS * 2 + SPAN / 2, RADIUS * 2 + SPAN / 2, FALSE);
	loadimage(&start, _T("start.jpg"), menuButtonSize, menuButtonSize, FALSE);
	loadimage(&save, _T("save.jpg"), menuButtonSize, menuButtonSize, FALSE);
	loadimage(&load, _T("load.jpg"), menuButtonSize, menuButtonSize, FALSE);
	loadimage(&leave, _T("exit.jpg"), menuButtonSize, menuButtonSize, FALSE);
}

int SMenu()				//展示菜单
{
	int choice = 0;
	closegraph();

	initgraph(800, 600); //初始化图形系统
	setbkcolor(BROWN); //设置图形窗口的背景颜色
	cleardevice(); //清屏幕
	putimage(0, 0, &bckgpic);
	putimage(50, 50, &title);
	
	//start
	putimage(menuLoc, 60, &start);
	//save button
	putimage(menuLoc, 180, &save);
	//load
	putimage(menuLoc, 300, &load);
	//leave
	putimage(menuLoc, 420, &leave);

	
	cout << "-来，和爷一起玩亚马逊棋-" << endl;
	cout << "输入选项对应的数字，回车" << endl;
	while (true)
	{
		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			//save
			if (msg.mkLButton)
			{
				int i = msg.x;
				int j = msg.y;
				//start
				if (i >= menuLoc && i <= menuLoc + menuButtonSize \
					&& j >= 60 && j <= 60 + menuButtonSize)
				{
					flagstart = 1;
					choice = 1;
				}
				//save
				if (i >= menuLoc && i <= menuLoc + menuButtonSize \
					&& j >= 180 && j <= 180 + menuButtonSize)
				{
					flg = 1;
					choice = 3;
				}
				//load
				if ((i >= menuLoc && i <= menuLoc + menuButtonSize \
					&& j >= 300 && j <= 300 + menuButtonSize)\
					|| msg.mkRButton)
				{
					if (!flg)
					{
						outtextxy(400, 300, _T("给爷保存"));
						continue;
					}
					else if (!flagstart)
					{
						outtextxy(400, 300, _T("给爷开始"));
						continue;
					}
					else
						choice = 2;

				}
				//exit
				if (i >= menuLoc && i <= menuLoc + menuButtonSize \
					&& j >= 420 && j <= 420 + menuButtonSize)
				{
					exit(0);
				}

				FlushMouseMsgBuffer();
				return choice;
			
			}
		}
	}
	return -1;
}

void InitGame()
{
	go = Qwhite;			//初始设置白棋先走
	for (int x = 0; x < Gsize; ++x)				//新游戏全部设为空
	{
		for (int y = 0; y < Gsize; ++y)
		{
			Gridinfo[x][y] = Blank;
		}
	}
	Gridinfo[0][(Gsize - 1) / 3] = Qblack;		//初始化棋子位子,下同
	Gridinfo[(Gsize - 1) / 3][0] = Qblack;
	Gridinfo[Gsize - 1 - ((Gsize - 1) / 3)][0] = Qblack;
	Gridinfo[Gsize - 1][(Gsize - 1) / 3] = Qblack;
	Gridinfo[0][Gsize - 1 - ((Gsize - 1) / 3)] = Qwhite;
	Gridinfo[(Gsize - 1) / 3][Gsize - 1] = Qwhite;
	Gridinfo[Gsize - 1 - ((Gsize - 1) / 3)][Gsize - 1] = Qwhite;
	Gridinfo[Gsize - 1][Gsize - 1 - ((Gsize - 1) / 3)] = Qwhite;
}


bool Rcheck(int x, int y)			//Rangechaeck，检查是不是在范围内
{
	if (x < 0 || x >= Gsize || y < 0 || y >= Gsize)
	{
		return false;
	}
	return true;
}

int Nextgo()				//现在该谁走了呢？告诉爷
{
	return go;
}


//画空白背景
void DRAW_BACKGROUND_BY_INDEX(int i, int j)
{
	int left, top, right, bottom;
	left = itemsize * i + UpperLeft;
	top = itemsize * j + UpperLeft;
	right = itemsize * i + itemsize + UpperLeft;
	bottom = itemsize * j + itemsize + UpperLeft;
	setfillcolor(WHITE);
	solidrectangle(left, top, right - SPAN, bottom - SPAN);
}

void DRAW_PLAY_BLACK_BY_INDEX(int i, int j)
{
	int left, top, right, bottom;
	left = itemsize * i + UpperLeft;
	top = itemsize * j + UpperLeft;
	right = itemsize * i + itemsize + UpperLeft;
	bottom = itemsize * j + itemsize + UpperLeft;
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	solidrectangle(left, top, right - SPAN, bottom - SPAN);
	putimage(left + SPAN / 2, top + SPAN / 2, &black);
}

void DRAW_PLAY_WHITE_BY_INDEX(int i, int j)
{
	int left, top, right, bottom;
	left = itemsize * i + UpperLeft;
	top = itemsize * j + UpperLeft;
	right = itemsize * i + itemsize + UpperLeft;
	bottom = itemsize * j + itemsize + UpperLeft;
	setfillcolor(WHITE);
	solidrectangle(left, top, right - SPAN, bottom - SPAN);
	setlinecolor(BLACK);
	putimage(left + SPAN / 2, top + SPAN / 2, &white);
}


//画白方高亮棋子
void DRAW_HIGHLIGHT_PLAY_WHITE_BY_INDEX(int i, int j) {
	//convert index 
	int left, top, right, bottom;
	left = itemsize * i + UpperLeft;
	top = itemsize * j + UpperLeft;
	right = itemsize * i + itemsize + UpperLeft;
	bottom = itemsize * j + itemsize + UpperLeft;

	setfillcolor(WHITE);
	solidrectangle(left, top, right - SPAN, bottom - SPAN);
	setlinecolor(BLACK);
	putimage(left + SPAN / 2, top + SPAN / 2, &white);

	setlinecolor(RED);
	circle(left + RADIUS + SPAN / 2, top + RADIUS + SPAN / 2, RADIUS - 1);
	circle(left + RADIUS + SPAN / 2, top + RADIUS + SPAN / 2, RADIUS + 1);
}

void DRAW_OBSTACLE_BY_INDEX(int i, int j)
{
	int left, top, right, bottom;
	left = itemsize * i + UpperLeft;
	top = itemsize * j + UpperLeft;
	right = itemsize * i + itemsize + UpperLeft;
	bottom = itemsize * j + itemsize + UpperLeft;
	setfillcolor(WHITE);
	solidrectangle(left, top, right - SPAN, bottom - SPAN);
	setlinecolor(BLACK);
	setfillcolor(BLUE);
	putimage(left + SPAN / 2, top + SPAN / 2, &arrow);
}

void Rwindow()			//刷新屏幕的样子
{
	cleardevice();
	for (int x = 0; x < Gsize; ++x)
	{
		for (int y = 0; y < Gsize; ++y)
		{
			if (Gridinfo[x][y] == Qblack)
			{
				DRAW_PLAY_BLACK_BY_INDEX(x, y);
			}
			else if (Gridinfo[x][y] == Qwhite)
			{
				if (x == whites_choice.x && y == whites_choice.y)
				{
					DRAW_HIGHLIGHT_PLAY_WHITE_BY_INDEX(x, y);
				}
				else
				{
					DRAW_PLAY_WHITE_BY_INDEX(x, y);
				}
			}
			else if (Gridinfo[x][y] == Arrow)
			{
				DRAW_OBSTACLE_BY_INDEX(x, y);
			}
			else
			{
				
				DRAW_BACKGROUND_BY_INDEX(x, y);
			}
		}
	}

	int type = Nextgo();
	if (type == Qwhite)
	{
		outtextxy(480, 20, _T("下一步: 白皇后"));//要修改，下同(这里就是后面的菜单)
	}
	else if (type == Qblack)
	{
		outtextxy(480, 20, _T("下一步: 黑皇后"));
	}
	else if (type == Arrow)
	{
		outtextxy(480, 20, _T("下一步: 　　 箭"));
	}
}

bool Tcheck(int x, int y, int type)		//typecheck在这个点是这个东西（黑/白/箭）
{
	if (Gridinfo[x][y] == type)
	{
		return true;
	}
	return false;
}

bool QWcheck(int x, int y)				//用于检测是不是白皇后
{
	return Tcheck(x, y, Qwhite);
}

void Hreset(int x, int y)			//highlightreset，重设
{
	whites_choice.x = -1;
	whites_choice.y = -1;
}

void Hset(int x, int y)				//highlightset，设置为高亮选中
{
	whites_choice.x = x;
	whites_choice.y = y;
}

bool Hcheck(int x, int y)				//highlightcheck，检查是不是被选中的
{
	if (whites_choice.x == x && whites_choice.y == y)
	{
		return true;
	}
	return false;
}

bool Blankcheck(int x, int y)					//Blankcheck，检查是不是空位
{
	return Tcheck(x, y, Blank);
}

bool HEcheck(int* x, int* y)				//highlight-existencecheck,检查有没有东西被选中
{
	if (whites_choice.x != -1 && whites_choice.y != -1)
	{
		*x = whites_choice.x;				//把xy放到选中的位子上
		*y = whites_choice.y;
		return true;
	}
	return false;
}

bool Vcheck(int x1, int y1, int x2, int y2)						//Validitycheck，检查这条路是否可行
{
	if (!Rcheck(x1, y1) || !Rcheck(x2, y2))
	{
		return false;
	}
	if (x1 == x2)			//横向走子
	{
		if (y1 == y2)		//根本没动，你走屁
		{
			return false;
		}
		if (y2 < y1)		//往上
		{
			y1 -= 1;
			for (; y2 < y1; y1--)
			{
				if (!Blankcheck(x1, y1))					//中间有障碍你走个屁
				{
					return false;
				}
			}
		}
		if (y2 > y1)				//往下
		{
			y1 += 1;
			for(; y2 > y1; y1++)
			{
				if (!Blankcheck(x1, y1))					//中间有障碍你走个屁
				{
					return false;
				}
			}
		}
	}
	else if (y1 == y2)				//纵向走子
	{
		if (x2 < x1)				//往左
		{
			x1 -= 1;
			for (; x2 < x1; x1--)
			{
				if (!Blankcheck(x1, y1))				//不想写了，懂得都懂
				{
					return false;
				}
			}
		}	
		else
		{
			x1 += 1;
			for (x1++; x2 > x1; x1++)
			{
				if (!Blankcheck(x1, y1))
				{
					return false;
				}
			}
		}
	}
	else     //斜向走子
	{
		if (x1 - x2 != y1 - y2 && x1 - x2 != y2 - y1)				//不是对角走法，爬
		{
			return false;
		}
		else
		{
			if (x1 < x2)
			{
				if (y1 < y2)
				{
					x1 += 1;
					y1 += 1;
					for (; x1 < x2; x1++, y1++)
					{
						if (!Blankcheck(x1, y1))
						{
							return false;
						}
					}
				}
				else
				{
					x1 += 1;
					y1 -= 1;
					for (; x1 < x2; x1++, y1--)
					{
						if (!Blankcheck(x1, y1))
						{
							return false;
						}
					}
				}
			}
			else
			{
				if (y1 < y2)
				{
					x1 -= 1;
					y1 += 1;
					for (; x1 > x2; x1--, y1++)
					{
						if (!Blankcheck(x1, y1))
						{
							return false;
						}
					}				}
				else
				{
					x1 -= 1;
					y1 -= 1;
					for (; x1 > x2; x1--, y1--)
					{
						if (!Blankcheck(x1, y1))
						{
							return false;
						}
					}
				}
			}
		}
	}
	return true;							//我这么严格的要求你都通过了，那确实可以走
}

bool Mcheck(int x1, int y1, int x2, int y2, int type)			//Mobilitycheck，检查是不是可以走通
{
	if (!Vcheck(x1, y1, x2, y2))								//这条路怕是走不通
	{
		return false;											//给爷爬，不准走
	}
	return true;												//能走
}

int SetType(int x, int y, int type)
{
	if (!Rcheck(x, y))					//出界了，爬
	{
		return -1;
	}
	Gridinfo[x][y] = type;					//把这个选中点设为当前走的类型棋子，如果type是空格那就说明，是棋子走了，这里空了，就像空巢老人。
	return 1;
}

void Tchange(int type)						//Typechange，改变要走的棋子类型
{
	go = type;
}

void getMove()                   //尹星铉 1800094617
{
	position w;

	for (int i = 0; i < Gsize; i++)
		for (int j = 0; j < Gsize; j++)
		{
			if (a[i][j] == grid_white)
			{
				w.x = i;        //
				w.y = j;
				w.s = 0;

				//memset(visQ_W, 0, sizeof(visQ_W)); //
				//memset(visK_W, 0, sizeof(visK_W));
				for (int i = 0; i < Gsize; i++)
					for (int j = 0; j < Gsize; j++)
					{
						visQ_W[i][j] = 0;
						visK_W[i][j] = 0;
					}
				visQ_W[i][j] = 1;
				visK_W[i][j] = 1;
				Q_move_W(w);
				K_move_W(w);
			}
			if (a[i][j] == grid_black)
			{
				w.x = i;
				w.y = j;
				w.s = 0;
				//memset(visQ_B, 0, sizeof(visQ_B));
				//memset(visK_B, 0, sizeof(visK_B));
				for (int i = 0; i < Gsize; i++)
					for (int j = 0; j < Gsize; j++)
					{
						visQ_B[i][j] = 0;
						visK_B[i][j] = 0;
					}
				visQ_B[i][j] = 1;
				visK_B[i][j] = 1;
				Q_move_B(w);
				K_move_B(w);
			}
		}
}
int Domove(int x0, int y0, int x1, int y1, int type)				//进行移动
{
	if (!Vcheck(x0, y0, x1, y1))			//不能走哥们儿
	{
		return -1;
	}

	int a = -1;
	int flag = 0;
	if (type == Qwhite || type == Qblack)				//这里是可以嵌套ai函数的，就是该黑色棋子走
	{
		a = SetType(x1, y1, type);						//走棋
		a = SetType(x0, y0, Blank);						//棋子走了，原来的位置就空了，活生生空巢老人
	}
	else if (type == Arrow)
	{
		a = SetType(x1, y1, type);						//放障碍,放障碍就是好，只用走，却不需要考虑回头的事情，可能自由人的人们就是如此吧。
	}
	else
	{
		flag = 1;
	}
	if (flag == 0)
	{
		flag = 0;
		return 1;
	}
}

bool Move(int x0, int y0, int x1, int y1, int x2, int y2, int color, bool check_only)  //张俊优 1800094804
{
	if ((!Rcheck(x0, y0)) || (!Rcheck(x1, y1)) || (!Rcheck(x2, y2)))
		return false;
	if (Gridinfo[x0][y0] != color || Gridinfo[x1][y1] != 0)
		return false;
	if ((Gridinfo[x2][y2] != 0) && !(x2 == x0 && y2 == y0))
		return false;
	if (!check_only)
	{
		Gridinfo[x0][y0] = 0;
		Gridinfo[x1][y1] = color;
		Gridinfo[x2][y2] = Arrow;
	}
	return true;
}

int BotChess()		//需要修改的嵌套部分开始,内容进行嵌套
{
	while (1)
	{
		int flag = 0;    //做标记是否重新开始
		turn++;

		double maxValue = -1000;
		double valueP = 0;

		//电脑做决策
		for (int i0 = 0; i0 < Gsize; ++i0) {
			for (int j0 = 0; j0 < Gsize; ++j0) {
				for (int k1 = 0; k1 < 8; ++k1) {
					for (int delta1 = 1; delta1 < Gsize; delta1++) {
						if (Gridinfo[i0][j0] == currBotColor)
						{
							int xx = i0 + dx[k1] * delta1;
							int yy = j0 + dy[k1] * delta1;
							if (Gridinfo[xx][yy] != 0 || !Rcheck(xx, yy))
								break;//不是空格或不在棋盘
							for (int l = 0; l < 8; ++l) {
								for (int delta2 = 1; delta2 < Gsize; delta2++) {
									int xxx = xx + dx[l] * delta2;
									int yyy = yy + dy[l] * delta2;         //实现queen move
									if (!Rcheck(xxx, yyy))
										break;
									if (Gridinfo[xxx][yyy] != 0 && !(i0 == xxx && j0 == yyy))//不能放在原来的位置或有棋的地方
										break;
									if (Move(i0, j0, xx, yy, xxx, yyy, currBotColor, true))
									{
										memcpy(a, Gridinfo, sizeof(Gridinfo));

										a[i0][j0] = 0;
										a[xx][yy] = currBotColor;
										a[xxx][yyy] = Arrow;      //模拟棋盘


										for (int i = 0; i < Gsize; i++)
											for (int j = 0; j < Gsize; j++)
											{
												Q_black[i][j] = 1000;
												Q_white[i][j] = 1000;
												Kblack[i][j] = 1000;
												Kwhite[i][j] = 1000;
											}
										getMove();
										getValue();
										valueP = v(turn);
										if (maxValue < valueP)
										{
											maxValue = valueP;
											startX = i0;
											startY = j0;
											resultX = xx;
											resultY = yy;
											obstacleX = xxx;
											obstacleY = yyy;
										}

									}
								}

							}
						}
					}

				}
			}
		}

		return Move(startX, startY, resultX, resultY, obstacleX, obstacleY, currBotColor, false);

	}
}

void Pget(int type, Select_position posArray[], int size)				//Positionget，获得皇后的位置;;
{
	int i = 0;
	for (int x = 0; x < Gsize; ++x)
	{
		for (int y = 0; y < Gsize; ++y)
		{
			if (Gridinfo[x][y] == type)
			{
				if (i < size)
				{
					posArray[i].x = x;				//标上
					posArray[i].y = y;
					i++;
				}
			}
		}
	}
}

bool QMcheck(int x, int y)					//Queenmobilitycheck，检查皇后还能不能动
{
	bool result = false;
	for (int i = 0; i < Dsize; i++)			
	{
		int nextX = -1;						//初始化位置
		int nextY = -1;
		nextX = x + Direction[0][i];
		nextY = y + Direction[1][i];
		
		if (Rcheck(nextX, nextY) && Blankcheck(nextX, nextY))//一个方向第一次坐标失效，后面的肯定也无效，故跳过，提高效率
		{
			result = true;
			break;
		}
	}
	return result;
}

bool PLcheck()							//playerlostcheck，检查玩家输没有。
{
	bool result = true;
	Select_position queenPos[4];				//一起来找找四个皇后的位置
	Pget(Qwhite, queenPos, 4);		//冲冲冲，找皇后
	for (int i = 0; i < 4; ++i)
	{
		if (QMcheck(queenPos[i].x, queenPos[i].y) == 1)
		{
			result = false;
			break;
		}
	}
	return result;
}

void END(int gameresult)
{
	settextstyle(30, 0, _T("宋体"));
	if (gameresult == Blackloses)
	{
		outtextxy(300, 200, _T("黑方 输!"));
	}
	else if (gameresult == Whiteloses)
	{
		outtextxy(300, 200, _T("白方 输!"));
	}
	outtextxy(300, 300, _T("按任意键返回菜单"));
	_getch();				// 按任意键继续
	closegraph();			// 关闭图形界面
	game = SMenu();
	//return gameresult;
}

int Rungame()
{

	closegraph();
	initgraph(640, 480);			//初始化画图
	setbkcolor(BLACK);			//设置当前线条颜色
	cleardevice(); //清屏幕
	Rwindow();				//刷新界面
	outtextxy(480, 0, _T("欢迎进入游戏!"));	//这里需要修改
	
	while (true)
	{
		if (MouseHit())		//检测鼠标的信息
		{
			MOUSEMSG msg = GetMouseMsg();
			if (msg.mkLButton)			//左键被按下了
			{
				int i = msg.x / itemsize;
				int j = msg.y / itemsize;
				if (QWcheck(i, j) && (Nextgo() == Qwhite))				//检查是不是白皇后以及是不是该白皇后走
				{
					if (Hcheck(i, j))			//检查是不是被选中的
					{
						Hreset(i, j);			//是，说明是重复点击，那么，重设
					}
					else
					{
						Hset(i, j);	//不是，说明不是重复点击，高亮选中
					}
				}														
				else if (Blankcheck(i, j) && (Nextgo() == Qwhite || Nextgo() == Arrow))					//检查是不是空位以及下一个是不是白皇后或箭走
				{
					int x, y;														//该人类放置障碍物了
					if (HEcheck(&x, &y))						//检查有没有被选中的
					{
						if (Nextgo() == Qwhite)							//检查是不是该白色走
						{
							if (Mcheck(x, y, i, j, Qwhite))							//检查能不能走
							{
								Domove(x, y, i, j, Qwhite);							//冲，移动去
								Hset(i, j);											//这个地方被设置成高亮，这样障碍从这里出发按照皇后走法放置
								Tchange(Arrow);										//变成放障碍咯
							}
						}
						else if (Nextgo() == Arrow)						//该放障碍了
						{
							if (Mcheck(x, y, i, j, Arrow))				//能走不？
							{
								Domove(x, y, i, j, Arrow);				//冲
								Hreset(x, y);							//放完障碍，高亮消失，该下一位选手表演了。
								Tchange(Qblack);						//黑色开始表演

								int a = BotChess();						//判断值
								if (a < 0)
								{
									gameresult = Blackloses;//机器输
									END(gameresult);
								}
								Tchange(Qwhite);
								if (PLcheck())
								{
									gameresult = Whiteloses;//玩家输
									END(gameresult);
								}
							}
						}
						else
						{
							assert(false);				//就不用刷新窗口了
						}
					}
				}
				Rwindow();					//刷新窗口
			}
			
			else if (msg.mkRButton)					//右键按下
			{
				if (flag == 0)
				{
					gameresult = SMenu();				//打开菜单
					flag = 1;
				}
				else
				{
					flag = 0;
					return Rungame();
				}
				if (gameresult != 2)				//只要你不要在玩的时候乱点读档，爷就不拦你。
				{
					return gameresult;
				}
			}
		}

	} 


}

int Read(int(*map)[Gsize][Gsize], int* next)		//读取不会（in）
{
	ifstream in;
	in.open("RECORD.DAT", ios_base::in);

	if (in.is_open())
	{
		for (int x = 0; x < Gsize; ++x)
		{
			for (int y = 0; y < Gsize; ++y)
			{
				if (!in.eof())
				{
					in >> (*map)[x][y];
				}
			}
		}

		in.close();
		return 0;
	}

	return -1;//读取失败
}

int LoadChess()
{
	if (Read(&(Gridinfo), &go) < 0)
	{
		cout << "读档失败！" << endl;
		system("pause");
		return 0;
	}
	return Rungame();
}

int Newgame()
{
	InitGame();			//初始化游戏
	return Rungame();			//开始玩，嘻嘻，给爷冲
}

int Save(int map[Gsize][Gsize], int next)			//这里也不会（out）
{
	ofstream out;
	out.open("RECORD.DAT", ios_base::out | ios::trunc);

	if (out.is_open())
	{
		for (int x = 0; x < Gsize; ++x)
		{
			for (int y = 0; y < Gsize; ++y)
			{
				cout << map[x][y] << endl;
			}
		}
		out.close();
		return 0;
	}

	return -1;//保存失败
}

int SaveChess()
{
	if (Save(Gridinfo, go) < 0)
	{
		cout << "存档失败！" << std::endl;
		system("pause");
	}
	return 0;
}


void K_move_W(position pre)                 //尹星铉 1800094617
{
	position st, next;
	queue<position>W;
	W.push(pre);

	while (!W.empty())
	{
		st = W.front();
		W.pop();
		for (int k = 0; k < 8; k++)
		{
			next.x = st.x + dx[k];
			next.y = st.y + dy[k];
			next.s = st.s + 1;

			if (a[next.x][next.y] == 0 && visK_W[next.x][next.y] == 0 && Rcheck(next.x, next.y))
			{
				Kwhite[next.x][next.y] = min(Kwhite[next.s][next.y], next.s);
				visK_W[next.x][next.y] = 1;
				W.push(next);
			}
		}
	}
}

void K_move_B(position pre)                //尹星铉 1800094617
{
	position st, next;
	queue<position>B;
	B.push(pre);

	while (!B.empty())
	{
		st = B.front();
		B.pop();
		for (int k = 0; k < 8; k++)
		{
			next.x = st.x + dx[k];
			next.y = st.y + dy[k];
			next.s = st.s + 1;

			if (a[next.x][next.y] == 0 && visK_B[next.x][next.y] == 0 && Rcheck(next.x, next.y))
			{
				Kblack[next.x][next.y] = min(Kblack[next.s][next.y], next.s);
				visK_B[next.x][next.y] = 1;
				B.push(next);
			}
		}
	}
}

void Q_move_W(position pre)                //尹星铉  1800094617
{
	position st, next;
	queue<position>W;
	W.push(pre);

	while (!W.empty())
	{
		st = W.front();
		W.pop();
		for (int k = 0; k < 8; k++)
		{
			next.x = st.x;
			next.y = st.y;
			next.s = st.s + 1;
			while (1)
			{
				next.x += dx[k];
				next.y += dy[k];
				if (visQ_W[next.x][next.y] == 1)
				{
					continue;
				}
				if (a[next.x][next.y] == 0 && visQ_W[next.x][next.y] == 0 && Rcheck(next.x, next.y))
				{
					//pre_map_Q[next.x][next.y].white_min_step = min(pre_map_Q[next.x][next.y].white_min_step, next.step);
					Q_white[next.x][next.y] = min(Q_white[next.x][next.y], next.s);
					visQ_W[next.x][next.y] = 1;
					W.push(next);
				}
				else
					break;

			}
		}
	}
}

void Q_move_B(position pre)                 //尹星铉 1800094617
{
	position st, next;
	queue<position>B;
	B.push(pre);

	while (!B.empty())
	{
		st = B.front();
		B.pop();
		for (int k = 0; k < 8; k++)
		{
			next.x = st.x;
			next.y = st.y;
			next.s = st.s + 1;
			while (1)
			{
				next.x += dx[k];
				next.y += dy[k];
				if (visQ_B[next.x][next.y] == 1)
				{
					continue;
				}
				if (a[next.x][next.y] == 0 && visQ_B[next.x][next.y] == 0 && Rcheck(next.x, next.y))
				{
					//pre_map_Q[next.x][next.y].black_min_step = min(pre_map_Q[next.x][next.y].black_min_step, next.step);
					Q_black[next.x][next.y] = min(Q_black[next.x][next.y], next.s);
					visQ_B[next.x][next.y] = 1;
					B.push(next);
				}
				else
					break;

			}
		}
	}
}





double m()           //尹星铉  1800094617        求空格的灵活度的函数
{
	double mob = 0;

	for (int i = 0; i < Gsize; i++)
		for (int j = 0; j < Gsize; j++)
		{
			mobility[i][j] = 0;
		}

	for (int i = 0; i < Gsize; i++)
		for (int j = 0; j < Gsize; j++)
		{
			for (int k = 0; k < 8; k++)           //求每一个空格的灵活度
			{
				if (i + dx[k] >= 0 && i + dx[k] < Gsize && j + dy[k] >= 0 && j + dy[k] < Gsize)
				{
					if (a[i + dx[k]][j + dy[k]] == 0)
					{
						mobility[i][j]++;
					}
					else
						break;
				}
			}
		}

	for (int i = 0; i < Gsize; i++)
		for (int j = 0; j < Gsize; j++)
		{
			if (a[i][j] == 0)
			{
				for (int k = 0; k < 8; k++)
				{

					int m1 = i, m2 = j;
					int count = 0;
					while (1)
					{
						count++;
						m1 += dx[k];
						m2 += dy[k];
						if (m1 >= 0 && m1 < Gsize && m2 >= 0 && m2 < Gsize)
						{
							if (a[m1][m2] == grid_black)
							{
								mob += mobility[i][j] / count * 1.0 * currBotColor;
								break;
							}
							else if (a[m1][m2] == grid_white)
							{
								mob -= mobility[i][j] / count * 1.0 * currBotColor;
								break;
							}
							else if (a[m1][m2] == Arrow)
							{
								break;
							}
							else
								continue;

						}
						else
							break;
					}
				}
			}
		}
	return mob;
}

double t1 = 0, t2 = 0, p1 = 0, p2 = 0, mob = 0;

void getValue()                    //尹星铉   1800094617      求territory 参数的函数
{
	double tempB = 1, tempW = 1;
	t1 = t2 = p1 = p2 = mob = 0;

	for (int i = 0; i < Gsize; i++)
		for (int j = 0; j < Gsize; j++)
		{
			if (a[i][j] == 0)
			{
				for (int k = 0; k < Q_black[i][j]; k++)     //       求position 特征值
				{
					tempB *= 0.5;
				}
				for (int k = 0; k < Q_white[i][j]; k++)
				{
					tempW *= 0.5;
				}
				p1 += (tempB - tempW) * currBotColor * 1.0;


				p2 += min(1.0, max(-1.0, ((Kwhite[i][j] - Kblack[i][j]) / 6.0))) * currBotColor * 1.0;

				if (Q_black[i][j] < Q_white[i][j])    //求territory 特征值
				{
					t1 += 1 * currBotColor;
				}
				if (Q_black[i][j] > Q_white[i][j])
				{
					t1 -= 1 * currBotColor;
				}
				if (Q_black[i][j] == Q_white[i][j] && Q_black[i][j] != 10000)
				{
					t1 -= K * currBotColor;

				}
				if (Kblack[i][j] < Kwhite[i][j])
				{
					t2 += 1 * currBotColor;
					;
				}
				if (Kblack[i][j] > Kwhite[i][j])
				{
					t2 -= 1 * currBotColor;
				}
				if (Kblack[i][j] == Kwhite[i][j] && Kblack[i][j] != 10000)
				{
					t2 -= K * currBotColor;           //t2
				}
			}
		}
	p1 *= 2;
	p2 *= 2;
	mob = m();
}

double v(int turn)      //尹星铉   1800094617   求最终评估值的函数
{
	double value = 0;
	int turn1 = turn;

	if (turn1 <= 14)
	{
		value = 0.2 * t1 + 0.48 * t2 + 0.11 * p1 + 0.11 * p2 + 0.2 * mob;
	}
	else if (turn1 >= 15 && turn1 <= 48)
	{
		value = 0.4 * t1 + 0.25 * t2 + 0.2 * p1 + 0.2 * p2 + 0.05 * mob;
	}
	else if (turn1 >= 49)
	{
		value = 0.8 * t1 + 0.1 * t2 + 0.05 * p1 + 0.05 * p2;
	}

	return value;
}


//从tcheck里面抽出来的：assert(Rcheck(x, y));		//（这个函数意为：如果判断回来的值是false，就终止运行下一条）先判断是不是在界面外

//从Vcheck抽出来的，assert(Rcheck(x1, y1) && Rcheck(x2, y2));					//assert检查前后是不是都在范围内，否则不进行下面的判断

int main()
{
	loadImages();
	game = SMenu();			//展示菜单
	while (true)
	{
		if (game == 1)
		{
			game = Newgame();
			continue;
		}
		if (game == 2)
		{
			game = LoadChess();
			continue;
		}

		if (game == 3)
		{
			SaveChess();
			game = SMenu();
		}

		if (game == 4)
		{
			;
		}
	}
	return 0;
}