/*
* 求数组不相邻元素之和的最大值
* 张雨泽 1900094801 
* 2019/11/25
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
    int n, a[100002] = {0}, dp[100002] = {0}, history[100002] = {0}, temp = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    //i med and time remaining j
    for (int i = 1; i <= n; i++) //at number i
    {
        if (history[i - 1] == 1) //if last number was used
        {
            if (dp[i - 2] + a[i] > dp[i - 1]) //if replacing last number with current number has a larger sum
            {
                dp[i] = dp[i - 2] + a[i];
                history[i - 1] = 0;
                history[i] = 1;
            } else
            {
                dp[i] = dp[i - 1]; //last number is larger
            }
        }
        else
        {
            dp[i] = dp[i - 1] + a[i]; //no neighboring number, free to use.
            history[i] = 1;
        }
    }


    cout << dp[n];

    system("pause");
	return 0;
}