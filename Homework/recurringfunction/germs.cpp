/*
* 附加题：查看菌落数目
* 张雨泽 1900094801 
* 2019/11/12
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
void detectFour(int, int);
int cnt = 0, dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0}, a[101][101] = {0}, flag = 1; //records steps
int m, n;

int main()
{

    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    detectFour(m / 2 - 1, n / 2 - 1); // start middle
    cout << cnt;
    system("pause");
    return 0;
}

void detectFour(int i, int j)
{
    int flag = 0, count = 0; //flag 0 new tribe, flag 1 tribe found
    //checking ending loop conditions
    if (flag == 1)
    {   for (int k = 0; k < 4; k++)
            if (a[i + dx[k]][j + dy[k]] == 1) //if still exists around, continue
            {
                count++;
            }
        if (count < 1 && i <= n && j <= m)
        {
            return;
        }
    }

    if(a[i][j] == 1)
    {
        a[i][j] = 0;
        if (flag == 0) //checking if new tribe
        {
            cnt++;
            flag = 1; //setting tribe found
        }
        for (int k = 0; k < 4; k++)
        {
            if (a[i + dx[k]][j + dy[k]] == 1)
            {
                flag = 1; //continuing tribe
                detectFour(i + dx[k], j + dy[k]);
            }
        }
        flag = 0;
    }
    else if (flag == 0 && a[i][j] == 0)
    {
        for (int s = 2, x = 2;  s < m / 2, x < n / 2; s++, x++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (a[i + dx[k] * x][j + dy[k] * s] == 1) //m row, n columns
                {
                    flag = 0; // new tribe
                    detectFour(i + dx[k] * x, j + dy[k] * s);
                }
            }
        }
    }
    
    return;    
}
