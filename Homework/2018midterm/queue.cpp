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
    int n, m, num, add, a[200001];
    char b[15];
    cin >> n;
    num = n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        if (b[0] == 'A')
        {
            cin >> add;
            a[num++] = add;
        }
        else 
        {
            if (num == 0)
            {
                cout << "NULL" << endl; continue;
            }
            int p = 0;
            for (int k = 1; k < num; ++k)
                if (a[k] < a[p])
                    p = k;
            cout << a[p] << endl;
            for (int k = p; k < num; k++)
                a[k] = a[k + 1];
            num --;
        }
    }
    return 0;

    

    system("pause");
	return 0;
}

