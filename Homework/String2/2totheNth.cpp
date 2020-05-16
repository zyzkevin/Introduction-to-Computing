/*
* 计算2的N次方
* 张雨泽 1900094801 
* 2019/10/31
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void pow(int *num, int);
const int max_len = 100;
unsigned result[max_len * 2];

int main()
{
    int num[max_len]; //this array stores a temporary result used later for addition
    int n;
    memset(result, 0, sizeof(result));
    memset(num, 0, sizeof(num));
    cin >> n;
    pow(num, n);
    int i = max_len - 1; 
    while (num[i] == 0) //finding first non-zero num
        i--;
    for (; i >= 0; i--) //output
        cout << num[i];
    system("pause");
	return 0;
}

void pow (int *num, int k)
{
    num[0] = 1;
    if (k == 0)
    {
        return;
    }

    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < max_len; i++)
        {
            num[i] *= 2; //multiplying by 2
        }
        for (int i = 0; i < max_len; i++)
            if (num[i] >= 10)
                {
                    num[i + 1] += (num[i] / 10); //adding 
                    num[i] = num[i] % 10; //keep the unit digit
                }
    }

    return;
}