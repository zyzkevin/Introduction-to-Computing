/*
* K进制数的子序列
* 张雨泽 1900094801 
* 2019/10/31
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    const int max_len = 40;
    int k, m, len, i, sum = 0, num[max_len] = {}, cnt = 1, temp_len;
    char a[max_len], x, b[max_len], temp[max_len];
    cin >> k >> x >> m >> x >> a;
    len = strlen(a);
    temp_len = len;

    for (i = len - 1; i >= 0; i--) //reversing order
    {
        if (a[len - i - 1] >= 'A' && a[len - i - 1] <= 'Z')
            num[i] = a[len - i -1] - 'A' + 10; //converting from 10+ letters to int
        else
        {
            num[i] = a[len - i - 1] - '0'; //converting to int
        }
    }
    while (m > 0)
    {
        m--;
        num[0]++;
        memset(temp, 0, sizeof(temp));
        for (int j = 0; j < len; j++)
        {
            if(num[j] >= k)
            {
                if (j == len - 1) temp_len++; //adding total length
                num[j] -= k;
                num[j + 1] ++;
            } 
            else break;
        }
        for (int j = temp_len - 1; j >= 0; j--)
            temp[j] = num[j] + '0'; //converting to int;
        for (int j = temp_len - 1; j >= 0; j--)
            cout << temp[j];
        if (cnt <= 4 && m != 0)
        {
            cout << ',';
            cnt++;
        }
        else if(cnt == 5)
        {
            cnt = 1; //resetting
            cout << endl;
        }
        len = temp_len; //diedai
    }



    system("pause");
	return 0;
}
