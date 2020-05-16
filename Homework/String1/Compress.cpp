/*
* 行程长度编码
* 张雨泽 1900094801 
* 2019/10/25
*/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[1000];
    int count = 1;

    cin >> str;

    //Changing all letters to lowercase

    if (str[0] >= 'A' && str[0] <= 'Z')
        str[0] += 32;

    for (int i = 1; i < strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;    

        if(str[i] == str[i - 1])
            count++;
        else
        {
            str[i - 1] -= 32;
            cout << "(" << str[i - 1] << "," << count << ")"; 
            count = 1;
        }

    }
    str[strlen(str) - 1] -= 32;
    cout << "(" << str[strlen(str) - 1] << "," << count << ")"; 


    system("pause");
	return 0;
}