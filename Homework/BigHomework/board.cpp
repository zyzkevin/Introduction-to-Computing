#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;
char board[10][10][5];
void printboard()
{
    system("cls");
    cout << "┌──┬──┬──┬──┬──┬──┬──┬──┐" << endl;
    for (int i = 0 ; i < 8 ; i++)
    {
        cout <<"│";
        for (int j = 0; j < 8; j++)
            cout << board[i][j] << "│" ;
        if (i < 7)
            cout << endl << "├──┼──┼──┼──┼──┼──┼──┼──┤" << endl;
    }
    cout << endl << "└──┴──┴──┴──┴──┴──┴──┴──┘" << endl;
}

void initAmazons()
{
    char init[8] = {02, 20, 50, 72, 05, 27, 57, 75};
   
    for (int i = 0 ; i < 10; i++)
        for (int j = 0; j < 10; j++)
            strcpy(board[i][j], "  ");
    for(int i = 0; i < 8; i++)
    {
        if (i < 4) strcpy(board[init[i] / 10][init[i] % 10], "⊕");
        else strcpy(board[init[i] / 10][init[i] % 10], "⊙");
    }

    printboard();
    cout << "(x,y) ? (x=-1 exit)";
}

void gotoxy(int x, int y)
{
    COORD coord = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void cursorGet(int *i, int *j, int player)
{
    int x = *i, y = *j;
    char c = ' ';
    gotoxy(x, y);

    c = getch(); //第一个 getch()的值是 224，代表是方向箭头键
    if (c != 13) 
        c = getch(); //第二个 getch() 读到的是方向箭头的 ascii 编码

    while (c != 13)
    {
        if (c == 72) //向下
        y -= 2;
        if (c == 75) //向左
        x -= 3;
        if (c == 77) //向上
        x += 3;
        if (c == 80) //向上
        y += 2;
        gotoxy(x, y);
        c = getch();
        if (c == 13) break;
        c = getch();
    }
    if (player > 0)
        strcpy(board[x/3 - 1][y/3 - 1], "⊕");
    else 
        strcpy(board[x/2 - 1][y/2 - 1], "⊙");
    
    *i = x;
    *j = y;

     
    
}

int main()
{
    //init
    int x = 12, y = 12, player = 1; char ch;
    initAmazons();

    while(x >= 0)
    {
        cursorGet(&x, &y, player);
        player = player * -1;
        printboard();
    }
    return 0;
}