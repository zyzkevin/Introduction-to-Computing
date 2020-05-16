#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "bot.h"
#include "play.h"

ST_ROUTE* route[MAX_ROUTE_SIZE] = {0}; //TODO:内存需释放

int InMap[GRIDSIZE][GRIDSIZE]; 
int OutMap[GRIDSIZE][GRIDSIZE]; 
int currentStep;


void CopyMap(int dest[GRIDSIZE][GRIDSIZE], int src[GRIDSIZE][GRIDSIZE])
{
	for(int x=0; x<GRIDSIZE; ++x)
		for(int y=0; y<GRIDSIZE; ++y)
		{
			dest[x][y] = src[x][y];
		}
}

void InputMap(int map[GRIDSIZE][GRIDSIZE], int step)
{
	CopyMap(InMap, map);
	CopyMap(OutMap, map);

	currentStep = step;
}

void OutputMap(int map[GRIDSIZE][GRIDSIZE])
{}

bool CreateMoves(int color, ST_ROUTE* route[], int* actual_size)
{
	ST_POSITION queenPos[4];
	GetQueenPosition(QUEEN_BLACK, queenPos, 4);

	ST_ROUTE p;
	for(int i=0; i<4; ++i)
	{
		p.start.x = queenPos[i].x;
		p.start.y = queenPos[i].y;
		SetType(queenPos[i].x, queenPos[i].y, BLANK);

		//枚举可能的End
		ST_ROUTE* routeTmp[MAX_ROUTE_SIZE];//TODO:需释放内存
		int actualSizeTmp = 0;//初始必需为0
		Create(p, 1, routeTmp, &actualSizeTmp);

		//枚举一定的End 和 Arrow
		for(int j=0; j<actualSizeTmp; ++j)
		{
			Create(*routeTmp[j], 2, route, actual_size);
		}

		SetType(queenPos[i].x, queenPos[i].y, QUEEN_BLACK);

		FreeRouteArray(routeTmp, actualSizeTmp);
	}

	return true;
}

void Create(ST_ROUTE pos, int posType, ST_ROUTE* route[], int* actual_size)
{
	for (int i = 0; i<DIRECTION_SIZE; ++i)
	{
		int t = 1;
		int nextX = -1;
		int nextY = -1;

		if(posType == 1)
		{
			nextX = pos.start.x + t * dt[0][i];
			nextY = pos.start.y + t * dt[1][i];
		}
		else if(posType == 2)
		{
			nextX = pos.end.x + t * dt[0][i];
			nextY = pos.end.y + t * dt[1][i];
		}
		else
		{
			assert(false);
		}

		if(!IsCoordinateValid(nextX, nextY))//一个方向第一次坐标失效，后面的肯定也无效，故跳过，提高效率
		{
			continue;
		}

		while(IsCoordinateValid(nextX, nextY) && IsBlank(nextX, nextY))
		{
			ST_ROUTE *p = new ST_ROUTE;
			route[*actual_size] = p;
			(*actual_size)++;

			if(p == NULL)
			{
				assert(false);
				return;
			}

			if(posType == 1)
			{
				p->start = pos.start;
				p->end.x = nextX;
				p->end.y = nextY;
			}
			else if(posType == 2)
			{
				p->start = pos.start;
				p->end = pos.end;
				p->arrow.x = nextX;
				p->arrow.y = nextY;
			}
			else
			{
				assert(false);
			}

			++t;

			if(posType == 1)
			{
				nextX = pos.start.x + t * dt[0][i];
				nextY = pos.start.y + t * dt[1][i];
			}
			else if(posType == 2)
			{
				nextX = pos.end.x + t * dt[0][i];
				nextY = pos.end.y + t * dt[1][i];
			}
			else
			{
				assert(false);
			}
		}
	}
}

bool SearchOneRoute(ST_ROUTE *r)
{
	int size = 0;//初始必需为0
	CreateMoves(QUEEN_BLACK, route, &size);

	if(size == 0)
	{
		return false;
	}

	srand(time(0));
	int choice = rand()%size;

	*r = *route[choice];

	FreeRouteArray(route, size);

	return true;
}

int BotChess()
{
	ST_ROUTE route;
	if(!SearchOneRoute(&route))
	{
		return  -1;
	}

	MakeMove(route);

	return 1;
}

void FreeRouteArray(ST_ROUTE* route[], int size)
{
	for(int i=0; i<size; ++i)
	{
		free(route[i]);
		route[i] = nullptr;
	}
}