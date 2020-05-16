/*
* 字符串中最长的连续出现的字符
* 张雨泽 1900094801 
* 2019/12/9
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    char s1[100], s2[100], s3[100];
    cin.getline(s1, 100, ',');
    cin.getline(s2, 100, ',');
    cin >> s3;
    int lens1 = strlen(s1); int lens2 = strlen(s2);

    char *p1 = strstr(s1, s2);
    char *p2 = s1 + lens1 - 1;
    while(strstr(p2, s3) == NULL)
        p2 --;
    

}

