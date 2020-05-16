// game of Amazons.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include <cstdlib>
using namespace std;


const int Qblack = 1, Arrow = 2, Qwhite = 3, Blank = 0, Gsize = 8, itemsize = 60, Dsize = 8, SPAN = 4;
const int Blackloses = -3, Whiteloses = -2;
const int RADIUS = itemsize / 2 - SPAN;
const int UpperLeft = 60;
const int menuButtonSize = 60;


int gridInfo[Gsize][Gsize] = { 0 };		//每个棋子的情况
int go = Qwhite;			//初始白棋先走
int Direction[2][Dsize] = { -1,-1,0,1,1,1,0,-1,0,1,1,1,0,-1,-1,-1 };		//八个移动方向
typedef struct position
{
	int x;
	int y;
}Select_position;
Select_position whites_choice = { -1, -1 };
typedef struct route
{
	Select_position start;
	Select_position end;
	Select_position arrow;
}Select_route;


int SMenu()				//展示菜单
{
	int choice;
	closegraph();				//还不懂为什么要closegraph
	cout << "-来，和爷一起玩亚马逊棋-" << endl;
	cout << "输入选项对应的数字，回车" << endl;
	while (true)
	{
		cout << "1.开始游戏" << endl;
		cout << "2.继续游戏" << endl;
		cout << "3.保存游戏" << endl;
		cout << "4.退出" << endl;
		cin >> choice;
		if (choice > 4 || choice < 1)
		{
			system("cls");
			cout << "给爷爬，好好写";
		}
		else
		{
			return choice;
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
			gridInfo[x][y] = Blank;
		}
	}
	gridInfo[0][(Gsize - 1) / 3] = Qblack;		//初始化棋子位子,下同
	gridInfo[(Gsize - 1) / 3][0] = Qblack;
	gridInfo[Gsize - 1 - ((Gsize - 1) / 3)][0] = Qblack;
	gridInfo[Gsize - 1][(Gsize - 1) / 3] = Qblack;
	gridInfo[0][Gsize - 1 - ((Gsize - 1) / 3)] = Qwhite;
	gridInfo[(Gsize - 1) / 3][Gsize - 1] = Qwhite;
	gridInfo[Gsize - 1 - ((Gsize - 1) / 3)][Gsize - 1] = Qwhite;
	gridInfo[Gsize - 1][Gsize - 1 - ((Gsize - 1) / 3)] = Qwhite;
}

int Nextgo()				//现在该谁走了呢？告诉爷
{
	return go;
}

void Rwindow()			//刷新屏幕的样子
{
	//cleardevice();
	for (int x = 0; x < Gsize; ++x)
	{
		for (int y = 0; y < Gsize; ++y)
		{
			if (gridInfo[x][y] == Qblack)
			{
				//在xy点画出该棋子
			}
			else if (gridInfo[x][y] == Qwhite)
			{
				if (x == whites_choice.x && y == whites_choice.y)
				{
					//高亮显示（画）该白棋，因为选中的就是他
				}
				else
				{
					//在xy处画白棋
				}
			}
			else if (gridInfo[x][y] == Arrow)
			{
				//在该点画障碍
			}
			else
			{
				//在该点画很普通的背景
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

bool Rcheck(int x, int y)			//Rangechaeck，检查是不是在范围内
{
	if (x < 0 || x >= Gsize || y < 0 || y >= Gsize)
	{
		return false;
	}
	return true;
}

bool Tcheck(int x, int y, int type)		//typecheck在这个点是这个东西（黑/白/箭）
{
	assert(Rcheck(x, y));		//（这个函数意为：如果判断回来的值是false，就终止运行下一条）先判断是不是在界面外

	if (gridInfo[x][y] == type)
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
	assert(Rcheck(x1, y1) && Rcheck(x2, y2));					//assert检查前后是不是都在范围内，否则不进行下面的判断

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
	gridInfo[x][y] = type;					//把这个选中点设为当前走的类型棋子，如果type是空格那就说明，是棋子走了，这里空了，就像空巢老人。
	return 1;
}

void Tchange(int type)						//Typechange，改变要走的棋子类型
{
	go = type;
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

int BotChess()		//需要修改的嵌套部分开始,内容进行嵌套
{
	
}

void Pget(int type, Select_position posArray[], int size)				//Positionget，获得皇后的位置
{
	assert(size == 4);					//如果size不是4，那就不要清零i

	int i = 0;
	for (int x = 0; x < Gsize; ++x)
	{
		for (int y = 0; y < Gsize; ++y)
		{
			if (gridInfo[x][y] == type)
			{
				if (i <= size)
				{
					posArray[i].x = x;				//标上
					posArray[i].y = y;
					i++;
				}
				/*assert(i < size);			//如果i > size，那就别改了

				posArray[i].x = x;
				posArray[i].y = y;
				i++;*/
			}
		}
	}
}

bool QMcheck(int x, int y)					//Queenmobilitycheck，检查皇后还能不能动
{
	assert(QWcheck(x, y));

	bool result = false;
	for (int i = 0; i < Dsize; i++)			//这里我写了i++，和源程序不同
	{
		//int t = 1;//仅需判断最近的位置
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

int Rungame()
{
	initgraph(640, 480);			//初始化画图
	setlinecolor(BLACK);			//设置当前线条颜色
	Rwindow();				//刷新界面
	outtextxy(480, 0, _T("欢迎进入游戏!"));	//这里需要修改
	int gameresult;
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
									goto END;							//去输出结果吧
								}
								Tchange(Qwhite);
								if (PLcheck())
								{
									gameresult = Whiteloses;//玩家输
									goto END;
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
				gameresult = SMenu();				//打开菜单
				if (gameresult != 2)				//只要你不要在玩的时候乱点读档，爷就不拦你。
				{
					return gameresult;
				}
			}
		}

	} 

END:
	settextstyle(30, 0, _T("宋体"));
	if (gameresult == Blackloses)
	{
		outtextxy(300, 200, _T("黑方 输!"));
	}
	else if (gameresult == Whiteloses)
	{
		outtextxy(300, 200, _T("白方 输!"));
	}
	else
	{
		assert(false);
	}
	_getch();				// 按任意键继续
	closegraph();			// 关闭图形界面
	return gameresult;
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
	if (Read(&(gridInfo), &go) < 0)
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
	std::ofstream out;
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
	if (Save(gridInfo, go) < 0)
	{
		cout << "存档失败！" << std::endl;
		system("pause");
	}
	return 0;
}



int main()
{
	int game = 0;
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
			break;//退出程序
		}
	}
	return 0;
}


void loadImages()
{
	loadimage(&black, _T("black.jpg"), RADIUS * 2 + SPAN / 2, RADIUS * 2 + SPAN / 2, FALSE);
	loadimage(&white, _T("white.jpg"), RADIUS * 2 + SPAN / 2, RADIUS * 2 + SPAN / 2, FALSE);
	loadimage(&save, _T("save.jpg"), menuButtonSize, menuButtonSize, FALSE);
	loadimage(&load, _T("load.jpg"), menuButtonSize, menuButtonSize, FALSE);
	loadimage(&leave, _T("exit.jpg"), menuButtonSize, menuButtonSize, FALSE);
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


void menuitems()
{
	MOUSEMSG msg = GetMouseMsg();
	//save button
	putimage(600, 50, &save);
	//main function
	if (msg.mkLButton >= 600 && msg.mkLButton <= 600 + menuButtonSize \
		&& msg.mkLButton >= 50 && msg.mkLButton <= 50 + menuButtonSize)
	{
		//save();
	}
	//load
	putimage(600, 110, &save);
	if (msg.mkLButton >= 600 && msg.mkLButton <= 600 + menuButtonSize \
		&& msg.mkLButton >= 110 && msg.mkLButton <= 110 + menuButtonSize)
	{
		//load();
	}
	//exit
	putimage(600, 50, &leave);
	if (msg.mkLButton >= 600 && msg.mkLButton <= 600 + menuButtonSize \
		&& msg.mkLButton >= 110 && msg.mkLButton <= 110 + menuButtonSize)
	{
		//load();
	}
}