#ifndef PLAY_H
#define PLAY_H

#include "map.h"

//�������Ӻͼ�������ԭ���꣬Ŀ�����꣬������
//����: 1.�ɹ� ����.ʧ��
int MoveToSetChessOfBlack(int x0, int y0, int x1,int y1, int x2, int y2);
int MoveToSetChessOfWhite(int x0, int y0, int x1,int y1, int x2, int y2);

//Ԥ �ƶ����������ӻ��
bool PreMoveToSetType(int x0, int y0, int x1,int y1, int type);

//�ƶ����������ӻ��
//����: 1.�ɹ� ����.ʧ��
int MoveToSetType(int x0, int y0, int x1,int y1, int type);

//�������ӻ��,��յ�
//����: 1.�ɹ� ����.ʧ��
int SetType(int x,int y, int type);

//��ȡ��������
//���� -1: ʧ�� 
int GetType(int x,int y);

//��һ���굽�ڶ����꣬·���Ƿ���Ч
bool IsRouteValid(int x_a, int y_a, int x_b, int y_b);

//�����Ƿ�����Ч��Χ��
bool IsCoordinateValid(int x, int y);

//�Ƿ�ڷ��ʺ�
bool IsQueenOfBlack(int x, int y);

//�Ƿ�׷��ʺ�
bool IsQueenOfWhite(int x, int y);

//�Ƿ��ǿյ�
bool IsBlank(int x, int y);

//�Ƿ��
bool IsObstacle(int x, int y);

//�Ƿ��Ǵ�type
bool IsThisType(int x, int y, int type);

//��ȡQueen����λ��
void GetQueenPosition(int type, ST_POSITION posArray[], int size);

//����
void MakeMove(ST_ROUTE r);

//����
void UnMakeMove(ST_ROUTE r);

bool HasHighLight(int* x, int* y);

//�Ƿ��Ѹ���
bool IsHighLight(int x, int y);

//������Ҹ�������
void SetHightLight(int x, int y);

//ȡ��������Ҹ�������
void UnSetHightLight(int x, int y);

//������һ��������
void SetNextType(int type);

//������һ��������
int GetNextType();

//�׷�����Ƿ�����
bool IsPlayerLost();

//�׷��ʺ��Ƿ���ڻ��ŵ�
bool IsQueenLive(int x, int y);

#endif
