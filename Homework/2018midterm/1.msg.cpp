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
    int n, msg;
    double cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> msg;
        if (msg <= 70)
            cnt++;
        else
        {
            cnt += msg / 70 + 1;
        }
        
    }
    cout << fixed << setprecision(1) << cnt * 0.1 ;
    system("pause");
	return 0;
}

