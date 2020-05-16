/*
* 附加题：查看菌落数目
* 张雨泽 1900094801 
* 2019/11/12
*/
#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
int Dfs(int, int);

int total, value, num, price[100] = {0}, minvalue = INT_MAX;

int main()
{
    cin >> num >> total;
    for (int i = 0; i < num; i++)
        cin >> price[i];
    Dfs(0, 0);
    if (minvalue == INT_MAX)
        cout << "0" << endl;
    else
        cout << minvalue << endl;
    return 0;
}

void Dfs(int No, int value)
{ 

    if (value >= total)
    {
        minvalue = minvalue < value? minvalue : value;
        return;
    }
    if(No == num)
        return;
        value += price[No];
        Dfs(No + 1, value);
        return;
        value -= No;
    }
    
}
