/*
* 集合里的乘法
* 张雨泽 1900094801 
* 2019/11/12
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
bool mult(int);
char *p = NULL;
int T, N;

int main()
{
    int i = 0, flag = 1; //flag记录是否为第一个单词
    char a[1000];
    while (cin >> a) //找到单词
    {
        p = a; //指向开头
        while (*p) //指针还在单词里
        {
            if (*p == 'e' || *p == 'a')
            {

                if (flag) {cout << a; flag = 0;} //第一次
                else cout << " " << a;
                break;
            }
            p++;
        }
    }
}

