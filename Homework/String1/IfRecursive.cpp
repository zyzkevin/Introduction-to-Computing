/*
* 判断字符串是否为回文
* 张雨泽 1900094801 
* 2019/10/25
*/

#include <iostream>
#include <string.h>
using namespace std;


int main()
{
    char str[100];
    cin >> str;
    int flag = 1, j = strlen(str) - 1;
    
    for (int i = 0; i < j; i++, j--)
        if (str[i] != str[j])
        {
            flag = 0;
            cout << "no" << endl;
            break;
        }
    if (flag)
        cout << "yes" << endl;


    system("pause");
	return 0;
}