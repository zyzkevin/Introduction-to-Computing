#include "map.h"
#include "macro_def.h"


int currBotColor;
int gridInfo[GRIDSIZE][GRIDSIZE] = { 0 };

ST_POSITION whiteSelectPos = {-1,-1};

int nextType = QUEEN_WHITE; //白方优先

//八个移动方向
int dt[2][DIRECTION_SIZE] = {-1,-1,0,1,1,1,0,-1,
	0,1,1,1,0,-1,-1,-1};
