/*
张雨泽 1900094801
八皇后问题
12/24
*/
#include<cstring>
#include <iostream>
using namespace std;
int num[93][9];
int dp[9] = {0};
int cnt = 0;
int flag; //success placement
void f(int i)
{
    int j, k, l;
    if(i == 9)
    {
        cnt++;
        for(k = 1; k <= 8; k++)
            num[cnt][k] = dp[k];
        dp[i - 1] = 0;
    }
    else
    {
        for(j = 1; j <= 8; j++)
        {
        flag = 1;
        for(k = 1; k < i; k++)
        {
            if(dp[k] == j || (i + j) == (k + dp[k]) || (i - j) == (k - dp[k])) // row or column
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            dp[i]=j;
            f(i+1);
        }
        }
        if(flag == 0) //retrieving
            dp[i - 1] = 0; //moving on, testing next
    }
}
int main(void)
{
    int i, j, k, n;
    for(i = 1; i <= 8; i++)
    {
        dp[1] = i;
        f(2);
    }
    cin >> n;
    while(n--)
    {
        cin >> k;
        for(i = 1; i <= 8; i++)
            cout << num[k][i];
        cout << endl;
    }
    return 0;
}