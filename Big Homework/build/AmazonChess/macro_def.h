#ifndef MACRO_DEF_H
#define MACRO_DEF_H

#define GRIDSIZE 8

#define OBSTACLE    2   //¼ý
#define BLANK       0   //¿ÕµØ
#define QUEEN_BLACK 1   //ºÚ»Êºó
#define QUEEN_WHITE 3  //°×»Êºó

#define BLACK_LOST -3
#define WHITE_LOST -2

#define MAX_ROUTE_SIZE  3500

#define GRID_ITEM_SIZE 60
#define RADIUS GRID_ITEM_SIZE/2 - SPAN
#define SPAN 4
#define DIRECTION_SIZE 8

//»­¿Õ°×±³¾°
#define DRAW_BACKGROUND(left, top, right, bottom) {\
	setfillcolor(WHITE);\
	solidrectangle(left, top, right-SPAN, bottom-SPAN);}
#define DRAW_BACKGROUND_BY_INDEX(i, j) DRAW_BACKGROUND(GRID_ITEM_SIZE*i, \
	GRID_ITEM_SIZE*j, \
	GRID_ITEM_SIZE*i+GRID_ITEM_SIZE, \
	GRID_ITEM_SIZE*j+GRID_ITEM_SIZE)

//»­¼ý
#define DRAW_OBSTACLE(left, top, right, bottom) {\
	setfillcolor(WHITE);\
	solidrectangle(left, top, right-SPAN, bottom-SPAN);\
	setlinecolor(BLACK);\
	setfillcolor(BLUE);\
	fillcircle(left+RADIUS+SPAN/2, top+RADIUS+SPAN/2, RADIUS);}
#define DRAW_OBSTACLE_BY_INDEX(i, j) DRAW_OBSTACLE(GRID_ITEM_SIZE*i, \
	GRID_ITEM_SIZE*j, \
	GRID_ITEM_SIZE*i+GRID_ITEM_SIZE, \
	GRID_ITEM_SIZE*j+GRID_ITEM_SIZE)

//»­ºÚ·½Æå×Ó
#define DRAW_PLAY_BLACK(left, top, right, bottom) {\
	setlinecolor(BLACK);\
	setfillcolor(WHITE);\
	solidrectangle(left, top, right-SPAN, bottom-SPAN);\
	setfillcolor(BLACK);\
	fillcircle(left+RADIUS+SPAN/2, top+RADIUS+SPAN/2, RADIUS);}
#define DRAW_PLAY_BLACK_BY_INDEX(i, j) DRAW_PLAY_BLACK(GRID_ITEM_SIZE*i, \
	GRID_ITEM_SIZE*j, \
	GRID_ITEM_SIZE*i+GRID_ITEM_SIZE, \
	GRID_ITEM_SIZE*j+GRID_ITEM_SIZE)

//»­°×·½Æå×Ó
#define DRAW_PLAY_WHITE(left, top, right, bottom) {\
	setfillcolor(WHITE);\
	solidrectangle(left, top, right-SPAN, bottom-SPAN);\
	setlinecolor(BLACK);\
	circle(left+RADIUS+SPAN/2, top+RADIUS+SPAN/2, RADIUS);}
#define DRAW_PLAY_WHITE_BY_INDEX(i, j) DRAW_PLAY_WHITE(GRID_ITEM_SIZE*i, \
	GRID_ITEM_SIZE*j, \
	GRID_ITEM_SIZE*i+GRID_ITEM_SIZE, \
	GRID_ITEM_SIZE*j+GRID_ITEM_SIZE)

//»­°×·½¸ßÁÁÆå×Ó
#define DRAW_HIGHLIGHT_PLAY_WHITE(left, top, right, bottom) {\
	setfillcolor(WHITE);\
	solidrectangle(left, top, right-SPAN, bottom-SPAN);\
	setlinecolor(BLACK);\
	circle(left+RADIUS+SPAN/2, top+RADIUS+SPAN/2, RADIUS);\
	setlinecolor(RED);\
	circle(left+RADIUS+SPAN/2, top+RADIUS+SPAN/2, RADIUS-1); \
	circle(left+RADIUS+SPAN/2, top+RADIUS+SPAN/2, RADIUS+1);}
#define DRAW_HIGHLIGHT_PLAY_WHITE_BY_INDEX(i, j) DRAW_HIGHLIGHT_PLAY_WHITE(GRID_ITEM_SIZE*i, \
	GRID_ITEM_SIZE*j, \
	GRID_ITEM_SIZE*i+GRID_ITEM_SIZE, \
	GRID_ITEM_SIZE*j+GRID_ITEM_SIZE)

#endif