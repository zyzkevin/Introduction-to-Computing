/*
* 附加题：查看菌落数目
* 张雨泽 1900094801 
* 2019/11/12
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
int f(int, int);

int a, n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    { 
        cin >> a;
        cout << f(a, 2) << endl;

    }
    system("pause");
    return 0;
}

int f(int x, int y)
{
    if (x < 2)
        return 0;
    if (x == 2)
        return 1;
    int b = (int)sqrt((double)x);
    int xnumber = 1;
    for (int i = y; i <= b; i++)
        if (x % i == 0)
            xnumber += f(x/i, i);
    return xnumber;
}
