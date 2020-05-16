/*
* RMB Pay
* 张雨泽 1900094801 
* 2019/10/31
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

void isFactor(int, int), output(int);
int isBigM(int);

int main()
{
    int grid[23] = {0}, history[23] = {0}, n, cnt = 1, loc = 1, new_loc;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> grid[i];
    while (loc < n + 1)
    {
        cnt++;
        
        if ((grid[loc] == 0)|| (history[loc] == 1))
        {
            history[loc] = 1;
            cnt++;
            loc++;
            continue;
        }
        else {
            new_loc = loc + grid[loc];
            if (new_loc < 0)
                new_loc = 0;
            history[loc] = 1;
            
            loc = new_loc;
        }
        
    }
    cout << cnt;
}
