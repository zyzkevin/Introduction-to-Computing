/*
* 附加题：查看菌落数目
* 张雨泽 1900094801 
* 2019/11/12
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int a[10000] = {0}, n, M[5100][1700] = {0}; //pos counts from right to left, pair of chopsticks from 0 to k.

void select (int pos, int pair)
{
    if (pos == n - pair * 3) //if pos = pair * 3, only one way of distributing
    {
        M[pos][pair] = M[pos + 2][pair - 1] + (a[pos] - a[pos + 1]) * (a[pos] - a[pos + 1]);
    }
    else
    { 
        M[pos][pair] = min(M[pos + 1][pair], (M[pos + 2][pair - 1] + (a[pos] - a[pos + 1]) * (a[pos] - a[pos + 1]))); //finding lowest sum, if lower, break apart pos + 2 with pair -1
    }
}

int main()
{
    int k;
    memset(M, 0, sizeof(M));
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    M[n - 3][1] = (a[n - 2] - a[n - 3]) * (a[n - 2] - a[n - 3]); //only one way of distributing one pair of chopsticks
    for (int i = n - 4; i >= 0; i--) //finding minimum
        M[i][1] = min(M[i + 1][1], (a[i + 1] - a[i]) * (a[i + 1] - a[i]));

    for (int pair = 2; pair <= k; pair++)
        for (int pos = n - pair * 3; pos >= 0; pos--)
            select(pos, pair);
    cout << M[0][k];
    system("pause");
    return 0;
}

