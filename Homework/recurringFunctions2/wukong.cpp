/*
* 附加题：查看菌落数目
* 张雨泽 1900094801 
* 2019/11/12
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0}, maze[50][50], history[50][50] = {0}, x, y;//x, y is location of wukong
int m, n;

bool solvemaze(int i, int j)
{
    if (history[i][j] == 1) return false; //already been here, cannot continue
    if (i >= m || i < 0 || j >= n || j < 0) return false; //going outside of maze
    if (maze[i][j] == 1) return false; //wall
    if (maze[i][j] == 3) return true; //found tangseng
    history[i][j] = 1; //updating trace

    for (int k = 0; k < 4; k++)
        if (solvemaze(i + dx[k], j + dy[k]))
            return true;
    return false; //all four directions did not return true
}

int main()
{
    int i, j;
    cin >> m >> n;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 2)
            { x = i; y = j; maze[i][j] = 0;} //found wukong
        } 

    


    if (solvemaze(x, y))
        cout << "YES";
    else cout << "NO" << endl;
    system("pause");
    return 0;
}

