#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;
void gotoxy(int x, int y)
{
    COORD coord = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
    int x = 10,y = 10;//光标的初始位置在 10,10
    char c = ' '; int flag = 1;
    gotoxy(x,y); //将光标定在 x，y 处
    c = getch(); //第一个 getch()的值是 224，代表是方向箭头键
    c = getch(); //第二个 getch() 读到的是方向箭头的 ascii 编码
    while (c != 27) //属于箭头则进入循环
    {
        if (c == 72) //向下
        y--;
        if (c == 75) //向左
        x--;
        if (c == 77) //向上
        x++;
        if (c == 80) //向上
        y++;
        gotoxy(x, y); //定位光标
        c = getch(); //第一个 getch()的值是 224，代表是方向箭头键
        c = getch(); //第二个 getch() 读到的是方向箭头的 ascii 编码
        if (c == 13)
        if (flag > 0)
        {
            cout << "○";
            flag = -flag;
        }
        else
        {
        cout << "●";
        flag = -flag;
        }
    }
    system("pause");
    return 0;                                                                                                                                                                                                                                                              
}