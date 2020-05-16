/*
* 一类括号匹配问题
* 张雨泽 1900094801 
* 2019/10/31
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    int grid[25] = {0}, action[25] = {0}, cnt = 0, pos = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> grid[i];
    }

    pos = 1;
    cnt = 1;
    action[0]++;
    while(1)
    {
        if (action[n + 1] >= 1)
            break;
        cnt++;
        
        if (action[pos] > 0 || (grid[pos] == 0 && pos > 0 && pos < n + 1))
        {
            action[pos]++;
            cnt++;
            pos++;
            continue;
        }
        action[pos]++;

        pos = pos + grid[pos];
        if (pos >= n + 1) pos = n+ 1;
        {
            action[pos]++;
        }
        if (pos <= 0) pos = 0;
        {
            action[pos]++;
        }


    }

    cout << cnt;


    system("pause");
	return 0;
}

