/*
* 字符串中最长的连续出现的字符
* 张雨泽 1900094801 
* 2019/12/9
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
char *p = NULL;
char c[200], a[200];

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        m = 0; //清零
        cin >> a;
        int len = strlen(a), cnt = 1;
        for (int j = 0; j < len; j++)
        {
            p = a + j;
            if (*(p - 1) == *p && j != 0) //上一个相同，并且不是第一个
                cnt++;
            if(*(p + 1) != *p || j == len - 1) //下一个不同，并不是最后一个数字
            {
                if (cnt > m)
                {
                    c[cnt] = a[j];
                    m = cnt;
                }
                cnt = 1;
            }
            
        }
        cout << c[m] << " " << m << endl;
    }
}

