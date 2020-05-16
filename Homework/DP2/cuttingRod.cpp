/*
* 附加题：查看菌落数目
* 张雨泽 1900094801 
* 2019/11/12
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int p[10000] = {0}, dp[10000] = {0}; //dp[i] is the best cutting for length i

int cuttingRod(int l)
{
    if (dp[l] > 0)
        return dp[l]; //skipping already recorded parts
    int temp = -1;
    if (l == 0)
        temp = 0;
    else
    {
        for (int i = 1; i <= l; i++)
        {
            int k = p[i] + cuttingRod(l - i); //cutting rod = price of current length + remaining length
            if (k > temp) //recording most value
                temp = k;
        }
    }
    dp[l] = temp; //best value at current length
    return temp;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    cuttingRod(n);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = p[i]; //not cutting
        for (int j = 1; j < i; j++) //cutting to i.
            dp[i] = max (dp[i], p[j] + dp[i - j]);
    }
    cout << dp[n];
    system("pause");
    return 0;
}

