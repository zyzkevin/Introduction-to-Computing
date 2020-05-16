/*
* 验证子串
* 张雨泽 1900094801 
* 2019/10/25
*/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str1[100], str2[100];
    cin >> str1 >> str2;
    int la = strlen(str1), lb = strlen(str2);
    int j, flag = 0;

    for (int i = 0; i <= lb - la; i++)
    {
        for (j = 0; j < la; j++)
            if (str1[j] != str2[i + j])
                break;
        if (j == la)
        {
            cout << str1 << " is substring of " << str2 << endl;
            return 0;
        }
    }

    for (int i = 0; i <= la - lb; i++)
    {
        for (j = 0; j < lb; j++)
            if (str1[i + j] != str2[j])
                break;
        if (j == lb)
        {
            cout << str2 << " is substring of " << str1 << endl;
            return 0;
        }
    }

    cout << "No substring" << endl;

    system("pause");
	return 0;
}