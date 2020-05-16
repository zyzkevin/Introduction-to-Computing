/*
* 循环移动
* 张雨泽 1900094801 
* 2019/12/6
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
bool mult(int);
int *p = NULL;


int main()
{
    int pos = 0, k, cnt = 0, flag = 0, temp = 0;
    char m;
    int a[130] = {0}, his[120] = {}, b[120];
    while ((m = cin.get()) != ' ')
    {
        a[pos] = m - '0';
        pos++;
    }
    cin >> k;

    if (k >= pos) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < pos; i++)
    {
        if (cnt >= k) break;
        if (his[i] == 1) continue; //already tested
        for (int j = i + 1; j <= i + k - cnt; j++)
        {
            if (a[i] > a[j])
            {
                for (int k = i; k <= j - 1; k++)
                {
                    his[k] = 1;
                    cnt++;
                }
                break;
            }
            
        }
    }
    p = b;
    for (int i = 0; i < (pos - k + cnt); i++)
    {
        if (his[i] == 1) continue;
        *p = a[i];
        p++;
        temp++;
    }
    for (int i = 0; i < temp - k + cnt; i++)
    {
        if (flag == 0 && b[i] == 0) continue;
        cout << b[i];
        flag = 1;
    }
    if (flag == 0) cout << 0 << endl;
    
    
}

