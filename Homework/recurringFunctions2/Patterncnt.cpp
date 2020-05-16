
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
char k[201][201] = {0};
int m, n, sum = 0, cnt = 0, dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1}, dy[8] = {0, -1, 1, 0, -1, 1, -1, 1}; //flag 0: no pattern found, flag 1: pattern found

void checkFour(int x, int y)
{    
    if (x >= 0 && x <= n && y >= 0 && y <= m && k[x][y] == '#') //pattern found, and within limits.
    {  
        k[x][y] = '-'; // deleting pattern
        sum++;
        for (int i = 0; i < 8; i++)
            checkFour(x + dx[i], y + dy[i]); //spreading in all 8 directions
    }

}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
            cin >> k[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            checkFour(i, j); //starts detecting from the center
            if (sum) cnt++; //if sum >=0, than pattern deleted.
            sum = 0; //resetting sum
        }
    cout << cnt;
    system("pause");
}


