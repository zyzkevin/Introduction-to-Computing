/*
张雨泽 1900094801
花生问题
12/23
*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    char a[100];
    cin >> a;
    int len = strlen(a);
    char ch1[1] = {a[1]}, ch2[1];
    char *p2 = NULL;
    int cnt = 0;
    for (int i = 1; i < len; i++)
        if (a[i] != ch1[0])
        {
            ch2[0] = a[i];
            break;
        }
    char temp[100];
    p2 = a;
    while (cnt < len)
    {
        while (*p2 != ch2[0] && *p2 != '0')
            p2++;
        if (*p2 == '0') break;
        char *p1 = p2 - 1;

        while (*p1 != ch1[0])
            p1--;
        cnt += 2;
        cout << p1 - a << " " << p2 - a << endl;
        *p1 = 'a';
        *p2 = 'a';
    }
        

}