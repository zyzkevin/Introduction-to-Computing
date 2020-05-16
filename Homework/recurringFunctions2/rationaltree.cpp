/*
* 水淹七军
* 张雨泽 1900094801 
* 2019/11/18
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int n, d, cnt = 0, branch = 0;//n-numerator, d-denominator, branch (0, 2), records left and right

void split(int num, int dem)
{
    cnt++;
    if (n == num && d == dem) 
        return;
    if (branch < 2)   
    { 
        if (cnt % 2) split(num, num + dem);
        branch++;
        dem -= num; //recalling
        split(num + dem, num);
        num -= dem;
    }
    else
    {
        branch = 0;
        if (cnt % 2) split(num, 2 * num + dem);
        else split(2 * dem + num, dem);
        
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> d;
        split(1, 1);
        cout << cnt << endl;
    }
    system("pause");
    return 0;
}

