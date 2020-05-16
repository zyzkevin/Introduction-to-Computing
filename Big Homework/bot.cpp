// 亚马逊棋（Amazons）简单交互样例程序
// 随机策略（由zhouhy修改）
// 作者：dgf123/syys
// 游戏信息：http://www.botzone.org/games#Amazons


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <algorithm>
#include <cstring>

#define GRIDSIZE 8
#define Gsize 8
#define OBSTACLE 2
#define judge_black 0
#define judge_white 1
#define grid_black 1
#define grid_white -1

using namespace std;

struct position
{
	int x;
	int y;
	int s;
};

int currBotColor; // 我所执子颜色（1为黑，-1为白，棋盘状态亦同）
int gridInfo[GRIDSIZE][GRIDSIZE] = { 0 }; // 先x后y，记录棋盘状态
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int Q_white[Gsize][Gsize] = { 0 };
int Q_black[Gsize][Gsize] = { 0 };
int visK_B[Gsize][Gsize] = { 0 };            //用来记录各自的queen move 和 king move
int visQ_B[Gsize][Gsize] = { 0 };
int visK_W[Gsize][Gsize] = { 0 };            //用来记录各自的queen move 和 king move
int visQ_W[Gsize][Gsize] = { 0 };
int Kwhite[Gsize][Gsize] = { 0 };
int mobility[Gsize][Gsize] = { 0 };
int Kblack[Gsize][Gsize] = { 0 };
int a[Gsize][Gsize] = { 0 }; //模拟棋盘
double K = 0.2;
int turn = 0;
double v(int);
void Q_move_W(position pre);
void K_move_W(position pre);
void Q_move_B(position pre);
void K_move_B(position pre);
void getValue();

// 判断是否在地图内
inline bool inMap(int x, int y)
{
	if (x < 0 || x >= GRIDSIZE || y < 0 || y >= GRIDSIZE)
		return false;
	return true;
}


// 在坐标处落子，检查是否合法或模拟落子
bool ProcStep(int x0, int y0, int x1, int y1, int x2, int y2, int color, bool check_only)
{
	if ((!inMap(x0, y0)) || (!inMap(x1, y1)) || (!inMap(x2, y2)))
		return false;
	if (gridInfo[x0][y0] != color || gridInfo[x1][y1] != 0)
		return false;
	if ((gridInfo[x2][y2] != 0) && !(x2 == x0 && y2 == y0))
		return false;
	if (!check_only)
	{
		gridInfo[x0][y0] = 0;
		gridInfo[x1][y1] = color;
		gridInfo[x2][y2] = OBSTACLE;
	}
	return true;
}


int startX, startY, resultX, resultY, obstacleX, obstacleY;

void K_move_W(position pre)
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

			if (a[next.x][next.y] == 0 && visK_W[next.x][next.y] == 0 && inMap(next.x, next.y))
			{
				Kwhite[next.x][next.y] = min(Kwhite[next.s][next.y], next.s);
				visK_W[next.x][next.y] = 1;
				W.push(next);
			}
		}
	}
}

void K_move_B(position pre)
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

			if (a[next.x][next.y] == 0 && visK_B[next.x][next.y] == 0 && inMap(next.x, next.y))
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
				if (a[next.x][next.y] == 0 && visQ_W[next.x][next.y] == 0 && inMap(next.x, next.y))
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

void Q_move_B(position pre)                 
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
				if (a[next.x][next.y] == 0 && visQ_B[next.x][next.y] == 0 && inMap(next.x, next.y))
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
							else if (a[m1][m2] == OBSTACLE)
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
	if (currBotColor == grid_white)
	{
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
	}
	else
	{
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
	}

	return value;
}

void getMove()                   
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

bool Move(int x0, int y0, int x1, int y1, int x2, int y2, int color, bool check_only)  
{
	if ((!inMap(x0, y0)) || (!inMap(x1, y1)) || (!inMap(x2, y2)))
		return false;
	if (gridInfo[x0][y0] != color || gridInfo[x1][y1] != 0)
		return false;
	if ((gridInfo[x2][y2] != 0) && !(x2 == x0 && y2 == y0))
		return false;
	if (!check_only)
	{
		gridInfo[x0][y0] = 0;
		gridInfo[x1][y1] = color;
		gridInfo[x2][y2] = OBSTACLE;
	}
	return true;
}

void BotChess()		//需要修改的嵌套部分开始,内容进行嵌套
{
	while (1)
	{
		turn++;

		double maxValue = -1000;
		double valueP = 0;

		//电脑做决策
		for (int i0 = 0; i0 < Gsize; ++i0) {
			for (int j0 = 0; j0 < Gsize; ++j0) {
				for (int k1 = 0; k1 < 8; ++k1) {
					for (int delta1 = 1; delta1 < Gsize; delta1++) {
						if (gridInfo[i0][j0] == currBotColor)
						{
							int xx = i0 + dx[k1] * delta1;
							int yy = j0 + dy[k1] * delta1;
							if (gridInfo[xx][yy] != 0 || !inMap(xx, yy))
								break;//不是空格或不在棋盘
							for (int l = 0; l < 8; ++l) {
								for (int delta2 = 1; delta2 < Gsize; delta2++) {
									int xxx = xx + dx[l] * delta2;
									int yyy = yy + dy[l] * delta2;         //实现queen move
									if (!inMap(xxx, yyy))
										break;
									if (gridInfo[xxx][yyy] != 0 && !(i0 == xxx && j0 == yyy))//不能放在原来的位置或有棋的地方
										break;
									if (Move(i0, j0, xx, yy, xxx, yyy, currBotColor, true))
									{
										memcpy(a, gridInfo, sizeof(gridInfo));

										a[i0][j0] = 0;
										a[xx][yy] = currBotColor;
										a[xxx][yyy] = OBSTACLE;      //模拟棋盘


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

	}
}

int main()
{
	int x0, y0, x1, y1, x2, y2;

	// 初始化棋盘
	gridInfo[0][(GRIDSIZE - 1) / 3] = gridInfo[(GRIDSIZE - 1) / 3][0]
		= gridInfo[GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)][0]
		= gridInfo[GRIDSIZE - 1][(GRIDSIZE - 1) / 3] = grid_black;
	gridInfo[0][GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)] = gridInfo[(GRIDSIZE - 1) / 3][GRIDSIZE - 1]
		= gridInfo[GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)][GRIDSIZE - 1]
		= gridInfo[GRIDSIZE - 1][GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)] = grid_white;


	int turnID;
	cin >> turnID;

	// 读入到当前回合为止，自己和对手的所有行动，从而把局面恢复到当前回合
	currBotColor = grid_white; // 先假设自己是白方
	for (int i = 0; i < turnID; i++)
	{
		// 根据这些输入输出逐渐恢复状态到当前回合

		// 首先是对手行动
		cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
		if (x0 == -1)
			currBotColor = grid_black; // 第一回合收到坐标是-1, -1，说明我是黑方
		else
			ProcStep(x0, y0, x1, y1, x2, y2, -currBotColor, false); // 模拟对方落子

																	// 然后是自己当时的行动
																	// 对手行动总比自己行动多一个
		if (i < turnID - 1)
		{
			cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
			if (x0 >= 0)
				ProcStep(x0, y0, x1, y1, x2, y2, currBotColor, false); // 模拟己方落子
		}
	}

	// 做出决策（你只需修改以下部分）

	BotChess();

	// 这里枚举了所有可能的下法，以便之后随机用……



	// 决策结束，输出结果（你只需修改以上部分）
	cout << startX << ' ' << startY << ' ' << resultX << ' ' << resultY << ' ' << obstacleX << ' ' << obstacleY << endl;
	return 0;
}