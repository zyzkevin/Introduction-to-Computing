#include <graphics.h>
#include <assert.h>
#include <conio.h>
#include <iostream>

#include "game.h"
#include "macro_def.h"
#include "map.h"
#include "bot.h"
#include "play.h"
#include "File.h"


void InitGame()
{
	nextType = QUEEN_WHITE;

	// 初始化棋盘
	for(int x=0; x<GRIDSIZE; ++x)
	{
		for(int y=0; y<GRIDSIZE; ++y)
		{
			gridInfo[x][y] = BLANK;
		}
	}

	//初始化棋子
	gridInfo[0][(GRIDSIZE - 1) / 3] = gridInfo[(GRIDSIZE - 1) / 3][0]
	= gridInfo[GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)][0]
	= gridInfo[GRIDSIZE - 1][(GRIDSIZE - 1) / 3] = QUEEN_BLACK;

	gridInfo[0][GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)] = gridInfo[(GRIDSIZE - 1) / 3][GRIDSIZE - 1]
	= gridInfo[GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)][GRIDSIZE - 1]
	= gridInfo[GRIDSIZE - 1][GRIDSIZE - 1 - ((GRIDSIZE - 1) / 3)] = QUEEN_WHITE;
}

void RefreshGridUI()
{
	//cleardevice();

	for(int x = 0; x < GRIDSIZE; ++x)
	{
		for(int y=0; y<GRIDSIZE; ++y)
		{
			if(gridInfo[x][y] == QUEEN_BLACK)
			{
				DRAW_PLAY_BLACK_BY_INDEX(x,y);
			}
			else if(gridInfo[x][y] == QUEEN_WHITE)
			{
				if(x == whiteSelectPos.x && y==whiteSelectPos.y)
				{
					DRAW_HIGHLIGHT_PLAY_WHITE_BY_INDEX(x,y);
				}
				else
				{
					DRAW_PLAY_WHITE_BY_INDEX(x,y);
				}
			}
			else if(gridInfo[x][y] == OBSTACLE)
			{
				DRAW_OBSTACLE_BY_INDEX(x,y);
			}
			else
			{
				DRAW_BACKGROUND_BY_INDEX(x,y);
			}
		}
	}

	int type = GetNextType();
	if(type == QUEEN_WHITE)
	{
		outtextxy(480, 20, _T("下一步: 白方皇后"));
	}
	else if(type == QUEEN_BLACK)
	{
		outtextxy(480, 20, _T("下一步: 黑方皇后"));
	}
	else if(type == OBSTACLE)
	{
		outtextxy(480, 20, _T("下一步: 　　　箭"));
	}	 
}

int ShowMenu()
{
	closegraph();

	std::cout<<"主菜单[输入选项对应的数字,并以回车键结束]"<<std::endl;
	do
	{		
		std::cout<<"1.开始游戏"<<std::endl;
		std::cout<<"2.继续游戏"<<std::endl;
		std::cout<<"3.保存游戏"<<std::endl;
		std::cout<<"4.退出"<<std::endl;
		std::cout<<"请选择：";

		int input;
		std::cin>>input;

		if(input>4 || input<1)
		{
			system("cls");
			std::cout<<L"输入数值超过选项范围,请重新输入!";
		}
		else
		{
			return input;
		}
	}while(true);

	return -1;
}

int NewGame()
{
	InitGame();
	return RunChess();
}

int LoadChess()
{
	if(Read(&(gridInfo), &nextType) < 0)
	{
		std::cout<<"读档失败！"<<std::endl;
		system("pause");
		return 0;
	}
	return RunChess();
}

int SaveChess()
{
	if(Save(gridInfo, nextType) < 0)
	{
		std::cout<<"存档失败！"<<std::endl;
		system("pause");
	}
	return 0;
}

int Quit()
{
	return 4;
}

int RunChess()
{	
	initgraph(640, 480);	
	setlinecolor(BLACK);

	RefreshGridUI();

	outtextxy(480, 0, _T("欢迎进入游戏!"));

	int result;
	do
	{
		if(MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			if(msg.mkLButton)
			{
				int i = msg.x / GRID_ITEM_SIZE;
				int j = msg.y / GRID_ITEM_SIZE;

				if(IsQueenOfWhite(i, j) && (GetNextType() == QUEEN_WHITE))
				{
					if(IsHighLight(i, j))
					{
						UnSetHightLight(i,j);
					}
					else
					{
						SetHightLight(i,j);
					}
				}
				else if(IsBlank(i, j) && (GetNextType() == QUEEN_WHITE || GetNextType() == OBSTACLE))
				{
					int x,y;
					if(HasHighLight(&x, &y))
					{
						if(GetNextType() == QUEEN_WHITE)
						{
							if(PreMoveToSetType(x,y,i,j,QUEEN_WHITE))
							{
								MoveToSetType(x,y,i,j,QUEEN_WHITE);
								SetHightLight(i,j);
								SetNextType(OBSTACLE);
							}
						}
						else if(GetNextType() == OBSTACLE)
						{
							if(PreMoveToSetType(x,y,i,j,OBSTACLE))
							{
								MoveToSetType(x,y,i,j,OBSTACLE);
								UnSetHightLight(x,y);									
								SetNextType(QUEEN_BLACK);

								int nRet = BotChess();
								if(nRet < 0)
								{
									result =  BLACK_LOST;//机器输
									goto END;
								}

								SetNextType(QUEEN_WHITE);

								if(IsPlayerLost())
								{
									result = WHITE_LOST;//玩家输
									goto END;
								}
							}
						}
						else
						{
							assert(false);
						}
					}
				}
				else
				{
					//无效点击，忽略
				}
				RefreshGridUI();
			}
			else if(msg.mkRButton)
			{
				result = ShowMenu();
				if(result!=2)
				{
					return result;
				}
			}
		}

	}while(true);

END:

	settextstyle(30, 0, _T("宋体"));
	if(result == BLACK_LOST)
	{
		outtextxy(300, 200, _T("黑方 输!"));
	}
	else if(result == WHITE_LOST)
	{
		outtextxy(300, 200, _T("白方 输!"));
	}
	else
	{
		assert(false);
	}

	_getch();				// 按任意键继续
	closegraph();			// 关闭图形界面
	return result;
}


