#ifndef PLAY_H
#define PLAY_H

#include "map.h"

//设置棋子和箭，传入原坐标，目的坐标，箭坐标
//返回: 1.成功 其它.失败
int MoveToSetChessOfBlack(int x0, int y0, int x1,int y1, int x2, int y2);
int MoveToSetChessOfWhite(int x0, int y0, int x1,int y1, int x2, int y2);

//预 移动并设置棋子或箭
bool PreMoveToSetType(int x0, int y0, int x1,int y1, int type);

//移动并设置棋子或箭
//返回: 1.成功 其它.失败
int MoveToSetType(int x0, int y0, int x1,int y1, int type);

//设置棋子或箭,或空地
//返回: 1.成功 其它.失败
int SetType(int x,int y, int type);

//获取坐标内容
//返回 -1: 失败 
int GetType(int x,int y);

//第一坐标到第二坐标，路径是否有效
bool IsRouteValid(int x_a, int y_a, int x_b, int y_b);

//坐标是否在有效范围内
bool IsCoordinateValid(int x, int y);

//是否黑方皇后
bool IsQueenOfBlack(int x, int y);

//是否白方皇后
bool IsQueenOfWhite(int x, int y);

//是否是空地
bool IsBlank(int x, int y);

//是否箭
bool IsObstacle(int x, int y);

//是否是此type
bool IsThisType(int x, int y, int type);

//获取Queen棋子位置
void GetQueenPosition(int type, ST_POSITION posArray[], int size);

//下子
void MakeMove(ST_ROUTE r);

//悔棋
void UnMakeMove(ST_ROUTE r);

bool HasHighLight(int* x, int* y);

//是否已高亮
bool IsHighLight(int x, int y);

//设置玩家高亮坐标
void SetHightLight(int x, int y);

//取消设置玩家高亮坐标
void UnSetHightLight(int x, int y);

//设置下一落子类型
void SetNextType(int type);

//返回下一落子类型
int GetNextType();

//白方玩家是否已输
bool IsPlayerLost();

//白方皇后是否存在活着的
bool IsQueenLive(int x, int y);

#endif
