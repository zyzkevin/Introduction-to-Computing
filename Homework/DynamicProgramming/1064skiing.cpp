#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

int h[102][102] = {0}, dp[102][102] = {{0}}, R, C;
int dpLong(int y, int x)
{
    if (dp[y][x] != 0)
        return dp[y][x];

    int len = 1; //longest length
    if (y - 1 >= 1 && h[y - 1][x] < h[y][x]) //detecting left 
        len = max(len, dpLong(y - 1, x) + 1);
    if (y + 1 <= R && h[y + 1][x] < h[y][x]) //detecting right
        len = max(len, dpLong(y + 1, x) + 1);
    if (x - 1 >= 1 && h[y][x - 1] < h[y][x]) //detecting down
        len = max(len, dpLong(y, x - 1) + 1);
    if (x + 1 <= C && h[y][x + 1] < h[y][x]) //detecting up
        len = max(len, dpLong(y, x + 1) + 1);
    return len;
    
}

int main()
{
    int longest = 1;
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> h[i][j];

    //i med and time remaining j
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            dp[i][j] = dpLong(i, j);
            if (dp[i][j] > longest) longest = dp[i][j];
        }


    cout << longest;

	return 0;
}