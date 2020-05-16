/*
* 一类括号匹配问题
* 张雨泽 1900094801 
* 2019/10/31
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;


int main()
{
    const int max_len = 1000;
    int cnt = 0, open[max_len], close[max_len], temp1, temp2, len, flag = 0, randomflag = 1; //cnt: num of brackets, open records '(', close ')', len: input, flag 0 if mismatch
    char str[max_len]; 
    cin >> str;
    len = strlen(str);

    memset(open, 0, sizeof(open));
    memset(close, 0, sizeof(close));
    
    for (int i = 0; str[i] != 0; i++) 
    {
        if (str[i] == ')')
        {
            randomflag = 0;
            for (int j = i; j >= 0; j--)
            {
                if (str[j] == '(')
                {
                    flag = 1;
                    open[cnt] = j;
                    close[cnt] = i;
                    break; //bracket pair found, breaking loop
                }
            }

            if (flag == 1)
            {
                str[i] = '2'; 
                str[open[cnt]] = '2'; //replacing the two brackets ith something random
                cnt++; //incrementing number of pairs
                flag = 0;
            }
        }
    }
    //detect mismatch
    for (int i = 0; str[i] != 0; i++) 
        if (str[i] == ')' || str[i] == '(')
        {
            cout << "mismatch";
            return 0;
        }



    for (int j = 0; j < cnt; j++)
        for (int i = 1; i < cnt; i++) //bubble sort
            if (close[i - 1] - open[i - 1] > close[i] - open[i]) 
            {
                temp1 = close[i - 1]; 
                temp2 = open[i - 1];
                close[i - 1] = close[i]; 
                open[i - 1] = open[i];
                close[i] = temp1; 
                open[i] = temp2;
            }

    for (int i = 0; i < cnt; i++)
        cout << open[i] + 1 << "," << close[i] + 1 << endl;

    if (randomflag)
        cout << "0,0";
    system("pause");
	return 0;
}

