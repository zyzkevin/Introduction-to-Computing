/*
* 配对碱基链
* 张雨泽 1900094801 
* 2019/10/31
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    char str[265], temp; //str stores input, temp stores coverted DNA
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < strlen(str); j++)
        {
            switch (str[j])
            {
                case 'A': temp = 'T'; break;
                case 'T': temp = 'A'; break;
                case 'C': temp = 'G'; break;
                case 'G': temp = 'C'; break;
            }
            cout << temp;
            if (j == strlen(str) - 1)
                cout << endl;
        }
    }
    system("pause");
	return 0;
}