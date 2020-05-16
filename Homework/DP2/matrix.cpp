/*
* 矩阵取数
* 张雨泽 1900094801 
* 2019/12/28
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, a[81] = {0}, dp[81][81] = {0}, lef, rig, sum = 0; //lef and rig records boundaries of taken numbers
    cin >> n >> m;

    
    //第i行时，j列
    for (int i = 1; i <= n; i++)
    {
       //memset(a, 0, sizeof(a));
        for (int j = 1; j <= m; j++)
        {
            cin >> a[j];
            dp[j][1] = a[j] * m;
        }
        
        for (int j = 2; j <= m; j++) //j numbers, position k
        {
            for (int k = 1; k <= m - j + 1; k++)
            {
                lef = (j + k - 1) % m;
                if (lef == 0) lef = m;
                rig = (k + 1) % m;
                if (rig == 0) rig = m;

                dp[k][j] = max((dp[rig][j - 1] + a[k] * (m - j + 1)), (dp[k][j - 1] + a[lef] * (m + 1 - j))); //finding larger side

            }
        } sum += dp[1][m];
    }
    cout << sum;
    return 0;
}

