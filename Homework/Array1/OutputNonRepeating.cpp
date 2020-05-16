/*
* 输出不重复的数字
* 张雨泽 1900094801 
* 2019/10/11
*/

#include <iostream>
using namespace std;

int main()
{
	int n, m, a[20000] = {0};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
        int j = 0;
        while (a[j] != a[i] && j < i) //finding repeats, stops if a repeat is found
            j++;
        if (j == i)
            if (i == 0) //no space if first element
	            cout << a[i];
            else
                cout << " " << a[i];
	}
	return 0;
} 
