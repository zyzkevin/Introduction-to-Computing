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

int main()
{
    int r, c, a[100][100] = {0};
    char n[10000];
    int cvt[1000] = {0}, New[10000] = {0};
    cin >> n;
    int len = strlen(n);
    int cnt = 0;
    int i = 0, j = 0;
    
    for (int i = 0; i < len; i++)
    {
        cvt[i] = n[i] - 'A' + 1; 
    }
    for (int i = 0; i < len * 2; i += 2)
    {
        New[i] = cvt[i / 10];
        New[i + 1] = cvt[i % 10];
    }

    while (cnt < len)
    {
        while (j < c - 1 && cnt < len)
        {
            j++;
            cout << New[i][j];
            cnt++;
        }
        while (i < r - 1 && cnt < len)
        {
            i++;
            a[i][j] = n[cnt] - '0';
            cnt++;
        }
        while (j > 0 && cnt < len)
        {
            j--;
            a[i][j] = n[cnt] - '0';
            cnt++;
        }
        while (i > 0 && cnt < len)
        {
            i--;
            a[i][j] = n[cnt] - '0';
            cnt++;
        }
    }
    system("pause");
    return 0;
}

