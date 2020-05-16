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
double dp = 0, p[100] = {0}, w[100] = {0}, m, n, ans = 0;
int flag = 0;

void fun(int x)
{
    flag = 0;
    for (int i = x + 1; i <= n; i++)
    {
        if (m >= w[i]) // enough space
        {
            flag = 1; // enough space
            dp += p[i];
            m -= w[i];
            fun(i);
            m += w[i]; //taking out
            dp -= p[i]; //recurring
        }
    }
    if (flag == 0) //not space
        ans = max(dp, ans);
}
int main()
{
    cin >> n >> m;
    //m = int(floor(m));
    for (int i = 1; i <= n; i++) //ith object
    {
        cin >> w[i] >> p[i]; // w weight, and v value
    }
    fun(0);
    cout << fixed << setprecision(5) << ans;

}

