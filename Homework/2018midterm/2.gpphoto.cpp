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
    int a[105] = {0};

    while (cin >> n && n != 0)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        int half = n / 2;
        sort(a, a + n);
        cout << a[half] << endl;
    }
    system("pause");
	return 0;
}

