#include"play.h"
#include "map.h"
#include <assert.h>

int MoveToSetChessOfBlack(int x0, int y0, int x1,int y1, int x2, int y2)
{
	if(!IsRouteValid(x0, y0, x1, y1) || !IsRouteValid(x1, y1, x2, y2))
	{
		return -1;
	}
	SetType(x1, y1, QUEEN_BLACK);
	SetType(x2, y2, OBSTACLE);

	return 1;
}

int MoveToSetChessOfWhite(int x0, int y0, int x1,int y1, int x2, int y2)
{
	if(!IsRouteValid(x0, y0, x1, y1) || !IsRouteValid(x1, y1, x2, y2))
	{
		return -1;
	}
	SetType(x1, y1, QUEEN_WHITE);
	SetType(x2, y2, OBSTACLE);

	return 1;
}

bool PreMoveToSetType(int x0, int y0, int x1,int y1, int type)
{
	if(!IsRouteValid(x0, y0, x1, y1))
	{
		return false;
	}

	return true;
}

int MoveToSetType(int x0, int y0, int x1,int y1, int type)
{
	if(!IsRouteValid(x0, y0, x1, y1))
	{
		return -1;
	}

	int nRet = -1;
	if(type == QUEEN_WHITE || type == QUEEN_BLACK)
	{
		nRet = SetType(x1, y1, type);
		nRet = SetType(x0, y0, BLANK);
	}
	else if(type == OBSTACLE)
	{
		nRet = SetType(x1, y1, type);
	}
	else
	{
		assert(false);
	}
	
	return 1;
}

int SetType(int x,int y, int type)
{
	if(!IsCoordinateValid(x, y))
	{
		return -1;
	}

	gridInfo[x][y] = type;

	return 1;
}

int GetType(int x,int y)
{
	if(!IsCoordinateValid(x, y))
	{
		return -1;
	}

	return gridInfo[x][y];
}

bool IsRouteValid(int x_a, int y_a, int x_b, int y_b)
{
	assert(IsCoordinateValid(x_a, y_a) && IsCoordinateValid(x_b, y_b));

	//if (x_a == x_b)//横向走子
	//{}
	//else if(y_a == y_b) //纵向走子
	//{}
	//else//斜向走子
	//{
	//}



		//
	if (x_a == x_b)
	{
		if (y_a == y_b) return 0;
		if (y_b < y_a)
			for (y_a--; y_b < y_a; y_a--)
			{
				if(!IsBlank(x_a, y_a)) return false;
			}
			if(y_b>y_a)
				for (y_a++; y_b > y_a; y_a++)
					if(!IsBlank(x_a, y_a)) return false;
	}
	else if (y_a == y_b)
	{
		if (x_b < x_a)
			for (x_a--; x_b < x_a; x_a--)
			{
				if(!IsBlank(x_a, y_a)) return false;
			}
		else
			for (x_a++; x_b > x_a; x_a++)
				if(!IsBlank(x_a, y_a)) return false;
	}
	else
	{
		if (x_a - x_b != y_a - y_b && x_a - x_b != y_b - y_a) return false;
		else
		{
			if (x_a < x_b)
			{
				if (y_a < y_b)
				{
					for (x_a++, y_a++; x_a < x_b; x_a++, y_a++)
						if(!IsBlank(x_a, y_a)) return false;
				}
				else
				{
					for (x_a++, y_a--; x_a < x_b; x_a++, y_a--)
						if(!IsBlank(x_a, y_a)) return false;
				}
			}
			else
			{
				if (y_a < y_b)
				{
					for (x_a--, y_a++; x_a > x_b; x_a--, y_a++)
						if(!IsBlank(x_a, y_a)) return false;
				}
				else
				{
					for (x_a--, y_a--; x_a > x_b; x_a--, y_a--)
						if(!IsBlank(x_a, y_a)) return false;
				}
			}
		}
	}

	return true;
}

bool IsCoordinateValid(int x, int y)
{
	if(x<0 || x>=GRIDSIZE
		||y<0 || y>=GRIDSIZE)
	{
		return false;
	}

	return true;
}

bool IsQueenOfBlack(int x, int y)
{
	return IsThisType(x, y, QUEEN_BLACK);
}

bool IsQueenOfWhite(int x, int y)
{
	return IsThisType(x, y, QUEEN_WHITE);
}

bool IsBlank(int x, int y)
{
	return IsThisType(x, y, BLANK);
}

bool IsObstacle(int x, int y)
{
	return IsThisType(x, y, OBSTACLE);
}

bool IsThisType(int x, int y, int type)
{
	assert(IsCoordinateValid(x, y));

	if(gridInfo[x][y] == type)
	{
		return true;
	}

	return false;
}

void GetQueenPosition(int type, ST_POSITION posArray[], int size)
{
	assert(size == 4);

	int i = 0;
	for(int x=0; x<GRIDSIZE; ++x)
	{
		for(int y=0; y<GRIDSIZE; ++y)
		{
			if(gridInfo[x][y] == type)
			{
				assert(i<size);

				posArray[i].x = x;
				posArray[i].y = y;
				++i;
			}
		}
	}
}

void MakeMove(ST_ROUTE r)
{
	int type = GetType(r.start.x, r.start.y);
	assert(type >= 0);

	SetType(r.end.x, r.end.y, type);
	SetType(r.start.x, r.start.y, BLANK);
	SetType(r.arrow.x, r.arrow.y, OBSTACLE);
}

void UnMakeMove(ST_ROUTE r)
{
	int type = GetType(r.end.x, r.end.y);
	assert(type >= 0);

	SetType(r.start.x, r.start.y, type);
	SetType(r.end.x, r.end.y, BLANK);
	SetType(r.arrow.x, r.arrow.y, BLANK);
}

bool HasHighLight(int* x, int* y)
{
	if(	whiteSelectPos.x != -1 && whiteSelectPos.y != -1)
	{
		*x = whiteSelectPos.x;
		*y = whiteSelectPos.y;
		return true;
	}

	return false;
}

bool IsHighLight(int x, int y)
{
	if(	whiteSelectPos.x == x && whiteSelectPos.y == y)
	{
		return true;
	}

	return false;
}

void SetHightLight(int x, int y)
{
	whiteSelectPos.x = x;
	whiteSelectPos.y = y;
}

void UnSetHightLight(int x, int y)
{
	whiteSelectPos.x = -1;
	whiteSelectPos.y = -1;
}

void SetNextType(int type)
{
	nextType = type;
}

int GetNextType()
{
	return nextType;
}

bool IsPlayerLost()
{
	bool result = true;

	ST_POSITION queenPos[4];
	GetQueenPosition(QUEEN_WHITE, queenPos, 4);

	for(int i=0; i<4; ++i)
	{
		if(IsQueenLive(queenPos[i].x, queenPos[i].y))
		{
			result = false;
			break;
		}
	}

	return result;
}

bool IsQueenLive(int x, int y)
{
	assert(IsQueenOfWhite(x, y));

	bool result = false;

	for (int i = 0; i<DIRECTION_SIZE; ++i)
	{
		int t = 1;//仅需判断最近的位置
		int nextX = -1;
		int nextY = -1;

		nextX = x + t * dt[0][i];
		nextY = y + t * dt[1][i];

		if(IsCoordinateValid(nextX, nextY) && IsBlank(nextX, nextY))//一个方向第一次坐标失效，后面的肯定也无效，故跳过，提高效率
		{
			result = true;
			break;
		}
	}

	return result;
}

