/*
* 顺序输出三个整数（使用指针完成）
* 张雨泽 1900094801 
* 2019/12/6
*/


#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

double *p = NULL;
int T, N;
double num[3];

void swap(double *x, double *y) 
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int flag0 = 0, flag1 = 0,flag2 = 0;
    p = num;
    scanf("%lf,%lf,%lf", &num[0], &num[1], &num[2]);
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < 2; i++)
            if (num[i] > num[i + 1])
                swap(num[i], num[i + 1]);
    if (num[0] == floor(num[0])) //检测输入是否为整数
        flag0 = 1;
    if (num[1] == floor(num[1])) //检测输入是否为整数
        flag1 = 1;
    if (num[2] == floor(num[2])) //检测输入是否为整数
        flag2 = 1;
    if (flag0)
        printf("%.0f,", num[0]);
    else
        printf("%.2f,", num[0]);
    if (flag1)
        printf("%.0f,", num[1]);
    else
        printf("%.2f,", num[1]);
    if (flag2)
        printf("%.0f", num[2]);
    else
        printf("%.2f", num[2]);
}
