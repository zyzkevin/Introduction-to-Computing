#ifndef BOT_H
#define BOT_H

#include "macro_def.h"
#include "map.h"


//��ͼ����
void CopyMap(int dest[GRIDSIZE][GRIDSIZE], int src[GRIDSIZE][GRIDSIZE]);

//map:�����ͼ step:��ǰ�ڼ���
void InputMap(int map[GRIDSIZE][GRIDSIZE], int step);                                             //�������
void OutputMap(int map[GRIDSIZE][GRIDSIZE]);                                                      //����������

//�������еĲ����б�
bool CreateMoves(int color, ST_ROUTE* route[], int* actual_size);
//posType: 1.start pos 2.end pos
void Create(ST_ROUTE pos, int posType, ST_ROUTE* route[], int* actual_size);

//���أ� false.�����ں��ʲ���
bool SearchOneRoute(ST_ROUTE *route);

//���أ�-1 ����
int BotChess();

void FreeRouteArray(ST_ROUTE* route[], int size);

#endif
