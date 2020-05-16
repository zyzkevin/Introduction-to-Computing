#include <easyx.h>
#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include<dos.h> 
#include<stdio.h> 

using namespace std;
IMAGE white;
IMAGE black;
IMAGE cundang;
IMAGE save;
IMAGE load;
IMAGE leave;

void printMsg()
{
    int i;
    for (i = 3; i < 7; i++)
    {
        // setcolor of cursor 
        setcolor(i);

        // print text at coordinate x,y; 
        outtextxy(100, 20 * i, "Geeks");

    }
}
const int SPAN = 4;
const int GRID_ITEM_SIZE = 60;
const int RADIUS = GRID_ITEM_SIZE / 2 - SPAN;
const int UpperLeft = 60;
const int menuButtonSize = 60;

void loadImages()
{
    loadimage(&black, _T("black.jpg"), RADIUS * 2 + SPAN / 2, RADIUS * 2 + SPAN / 2, FALSE);
    loadimage(&white, _T("white.jpg"), RADIUS * 2 + SPAN / 2, RADIUS * 2 + SPAN / 2, FALSE);
    loadimage(&save, _T("save.jpg"), menuButtonSize, menuButtonSize, FALSE);
    loadimage(&load, _T("load.jpg"), menuButtonSize, menuButtonSize, FALSE);
    loadimage(&leave, _T("exit.jpg"), menuButtonSize, menuButtonSize, FALSE);
}
//画空白背景
void DRAW_BACKGROUND_BY_INDEX(int i, int j)
{
    int left, top, right, bottom;
    left = GRID_ITEM_SIZE * i + UpperLeft;
    top = GRID_ITEM_SIZE * j + UpperLeft;
    right = GRID_ITEM_SIZE * i + GRID_ITEM_SIZE + UpperLeft;
    bottom = GRID_ITEM_SIZE * j + GRID_ITEM_SIZE + UpperLeft;
    setfillcolor(WHITE);
    solidrectangle(left, top, right - SPAN, bottom - SPAN);
}

void DRAW_PLAY_BLACK_BY_INDEX(int i, int j)
{
    int left, top, right, bottom;
    left = GRID_ITEM_SIZE* i + UpperLeft;
    top = GRID_ITEM_SIZE * j + UpperLeft;
    right = GRID_ITEM_SIZE * i + GRID_ITEM_SIZE + UpperLeft;
    bottom = GRID_ITEM_SIZE * j + GRID_ITEM_SIZE + UpperLeft;
    setlinecolor(BLACK);
    setfillcolor(WHITE);
    solidrectangle(left, top, right - SPAN, bottom - SPAN);
    putimage(left + SPAN / 2, top + SPAN / 2, &black);
}

void DRAW_PLAY_WHITE_BY_INDEX(int i, int j)
{
    int left, top, right, bottom;
    left = GRID_ITEM_SIZE* i + UpperLeft;
    top = GRID_ITEM_SIZE * j + UpperLeft;
    right = GRID_ITEM_SIZE * i + GRID_ITEM_SIZE + UpperLeft;
    bottom = GRID_ITEM_SIZE * j + GRID_ITEM_SIZE + UpperLeft;
    setfillcolor(WHITE);
    solidrectangle(left, top, right - SPAN, bottom - SPAN);
    setlinecolor(BLACK);
    putimage(left + SPAN / 2, top + SPAN / 2, &white);
}


//画白方高亮棋子
void DRAW_HIGHLIGHT_PLAY_WHITE_BY_INDEX(int i, int j) {
    //convert index 
    int left, top, right, bottom;
    left = GRID_ITEM_SIZE* i + UpperLeft;
    top = GRID_ITEM_SIZE * j + UpperLeft;
    right = GRID_ITEM_SIZE * i + GRID_ITEM_SIZE + UpperLeft;
    bottom = GRID_ITEM_SIZE * j + GRID_ITEM_SIZE + UpperLeft;

    setfillcolor(WHITE);
    solidrectangle(left, top, right - SPAN, bottom - SPAN);
    setlinecolor(BLACK);
    putimage(left + SPAN / 2, top + SPAN / 2, &white);

    setlinecolor(RED);
    circle(left + RADIUS + SPAN / 2, top + RADIUS + SPAN / 2, RADIUS - 1);
    circle(left + RADIUS + SPAN / 2, top + RADIUS + SPAN / 2, RADIUS + 1);
}


void menuitems()
{
    MOUSEMSG msg = GetMouseMsg();
    //save button
    putimage(600, 50, &save);
    //main function
    if (msg.mkLButton >= 600 && msg.mkLButton <= 600 + menuButtonSize \
        && msg.mkLButton >= 50 && msg.mkLButton <= 50 + menuButtonSize)
    {
        //save();
    }
    //load
    putimage(600, 110, &save);
    if (msg.mkLButton >= 600 && msg.mkLButton <= 600 + menuButtonSize \
        && msg.mkLButton >= 110 && msg.mkLButton <= 110 + menuButtonSize)
    {
        //load();
    }
    //exit
    putimage(600, 50, &leave);
    if (msg.mkLButton >= 600 && msg.mkLButton <= 600 + menuButtonSize \
        && msg.mkLButton >= 110 && msg.mkLButton <= 110 + menuButtonSize)
    {
        //load();
    }
}


    int main()
    {
        initgraph(800, 600); //初始化图形系统
        setbkcolor(BROWN); //设置图形窗口的背景颜色
        cleardevice(); //清屏幕
        //下面行读取图像文件
        /*loadimage(&black, _T("black.png"), 54, 54, FALSE);
        loadimage(&white, _T("white.png"), 54, 54, FALSE);
        loadimage(&cundang, _T("cundang.png"), 141, 50, FALSE);
        */
        loadImages();
        //下面行显示图像文件
        DRAW_PLAY_BLACK_BY_INDEX(1, 1);

        menuitems();
        DRAW_PLAY_WHITE_BY_INDEX(1, 3);
        DRAW_HIGHLIGHT_PLAY_WHITE_BY_INDEX(1, 5);



        //下面代码网格
        //fillrectangle(60, 60, 540, 540);
        setcolor(GREEN);
        line(60, 120, 540, 120);
        line(60, 180, 540, 180);
        line(60, 240, 540, 240);
        line(60, 300, 540, 300);
        line(60, 360, 540, 360);
        line(60, 420, 540, 420);
        line(60, 480, 540, 480);
        line(120, 60, 120, 540);
        line(180, 60, 180, 540);
        line(240, 60, 240, 540);
        line(300, 60, 300, 540);
        line(360, 60, 360, 540);
        line(420, 60, 420, 540);
        line(480, 60, 480, 540);
        //下面代码鼠标功能
        while (1)
        {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.mkLButton >= 600 && msg.mkLButton <= 741 && msg.mkLButton >= 490 && msg.mkLButton <= 540)
            {
                printMsg();

            }
            FlushMouseMsgBuffer();
        }
        return 0;
    }
