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

extern ST_POSITION whiteSelectPos;//��ҵ�ǰѡ�лʺ������(-1,-1��ʾȡ��ѡȡ��)

//ָ����һ���ӵ�����
extern int nextType;

extern int dt[2][DIRECTION_SIZE];


#endif
