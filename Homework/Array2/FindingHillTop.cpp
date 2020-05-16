/*
* 寻找山顶
* 张雨泽 1900094801 
* 2019/10/18
*/

#include <iostream>
using namespace std;

int main()
{
int m, n, a[22][22] = {0};
    cin >> m >> n;
    for (int i = 1; i < m + 1; i++) //starts from row 1, column 1, and ends 1 + m
        for(int j = 1; j < n + 1; j++)
        {
            cin >> a[i][j];
        }

    for (int i = 1; i < m + 1; i++)
        for(int j = 1; j < n + 1; j++)
        {
            if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1])
                {
                    cout << i - 1 << " " << j - 1<< endl;
                    j++; //skips adjacent, b/c adjacent cannot be larger than current 
                }
        }
    system("pause");
	return 0;
}