#ifndef MAP_H
#define MAP_H

#include "macro_def.h"

typedef struct position
{
	int x;
	int y;
}ST_POSITION;

typedef struct route 
{
	ST_POSITION start; 
	ST_POSITION end;   
	ST_POSITION arrow;
}ST_ROUTE;


extern int currBotColor;
extern int gridInfo[GRIDSIZE][GRIDSIZE]; 

extern ST_POSITION whiteSelectPos;//玩家当前选中皇后的坐标(-1,-1表示取消选取中)

//指定下一落子的类型
extern int nextType;

extern int dt[2][DIRECTION_SIZE];


#endif
