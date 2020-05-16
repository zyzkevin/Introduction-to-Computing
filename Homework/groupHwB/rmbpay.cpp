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
int factorSum();
int cnt = 0, factor[1000] = {0};

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            isFactor(j, i);
        if (factorSum() == i)
            output(i);
        cnt = 0;
        memset(factor, 0, sizeof(factor));
    }
}

void isFactor(int i, int j)
{
    if (j % i == 0)
        factor[cnt++] = i;
}

int factorSum()
{
    int sum = 0;
    for (int i = 0; i < cnt; i++)
        sum += factor[i];
    return(sum);
}
void output(int i)
{
    cout << i << " its factors are " << factor[0];
    for (int i = 1; i < cnt; i++)
        cout << "," << factor[i];
    cout << endl;
}
