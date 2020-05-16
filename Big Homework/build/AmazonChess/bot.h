#ifndef BOT_H
#define BOT_H

#include "macro_def.h"
#include "map.h"


//地图复制
void CopyMap(int dest[GRIDSIZE][GRIDSIZE], int src[GRIDSIZE][GRIDSIZE]);

//map:输入地图 step:当前第几步
void InputMap(int map[GRIDSIZE][GRIDSIZE], int step);                                             //输入棋局
void OutputMap(int map[GRIDSIZE][GRIDSIZE]);                                                      //处理并输出棋局

//构划可行的操作列表
bool CreateMoves(int color, ST_ROUTE* route[], int* actual_size);
//posType: 1.start pos 2.end pos
void Create(ST_ROUTE pos, int posType, ST_ROUTE* route[], int* actual_size);

//返回： false.不存在合适操作
bool SearchOneRoute(ST_ROUTE *route);

//返回：-1 已输
int BotChess();

void FreeRouteArray(ST_ROUTE* route[], int size);

#endif
