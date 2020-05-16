/*
张雨泽 1900094801
花生问题
12/23
*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
struct window
{
    int no;
    int x;
    int y;
    int w;
    int h;
};
int main()
{
    int n, flag = 0;
    int clk;
    window a[1001], temp;
    int clickx = 0, clicky = 0; //click pos
    cin >> n >> clk;
    for (int i = 0; i < n; i++)  
        cin >> a[i].no >> a[i].x >> a[i].y >> a[i].w >> a[i].h;
    while (clk--)
    {
        flag = 0;
        cin >> clickx >> clicky;
        for (int i = 0; i < n; i++)
        {
            if (clickx >= a[i].x && clickx < a[i].x + a[i].w && clicky >= a[i].y && clicky < a[i].y + a[i].h) //within borders        
            {
                cout << a[i].no << " " << clickx - a[i].x << " " << clicky - a[i].y << endl;
                temp = a[i];
                for (int j = i; j > 0; j--)
                    a[j] = a[j - 1]; //moving back
                a[0] = temp;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "desktop!" << endl;
    }
    
}


