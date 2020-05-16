/*
* 水淹七军
* 张雨泽 1900094801 
* 2019/11/18
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0}, height[200][200], x, y, t1, t2, flag = 0;//x, y is location of wukong
int m, n;

bool spreadWater(int i, int j, int h)
{
    if (i < 0 || i >= m || j < 0 || j >= n) return false;
    if (height[i][j] > h) return false;
    if (i == t1 && j == t2 && h > height[i][j]) return true; //controlcenter flooded
    //else, looping
    height[i][j] = h;
    for (int k = 0; k < 4; k++)
        if (spreadWater(i + dx[k], j + dy[k], h))
            return true;
    return false; //cannot spread towards all four directions, returning false
}

int main()
{
    int i, j, k, p;
    cin >> k;
    while (k--)
    {
    flag = 0; //resetting flag
    cin >> m >> n;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cin >> height[i][j];
        } 
    int temp, temp1, temp2; // temp is height of starting point, temp1 and temp2 are its coordinates
    cin >> t1 >> t2 >> p; 
    for (int l = 0; l < p; l++)
    {
        cin >> temp1 >> temp2;
        temp = height[temp1][temp2];
        height[temp1][temp2] = 0; //setting its own water level to zero, so that it wouldn't return false
        if (spreadWater(temp1, temp2, temp)) flag = 1;
    }
    if (flag)
        cout << "Yes" << endl;
    else cout << "No" << endl;
    }
    

    system("pause");
    return 0;
}

