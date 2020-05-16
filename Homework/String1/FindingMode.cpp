/*
* 求序列中的众数
* 张雨泽 1900094801 
* 2019/10/26
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N, j = 0, len, max = 0, cnt[128] = {0}, k = 1, pos = 0, flag = 1; //records first effective number
    char prestr[1000], str[128][1000];
    cin >> N;
    for (int i = 1; i <= N; i++)
    {

        cin >> prestr;
        len = strlen(prestr);
        for (j = 0; (prestr[j] < '1' || prestr[j] > '9') && j < len; j++);
        if (j == len)
            strcpy(str[i], "0");
        else if (prestr[0] == '-')
        {
            strcpy(str[i], "-");
            strcat(str[i], prestr + j); //adding numbers behind 0
        }
        else
            strcpy(str[i], prestr + j);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            if (strcmp(str[i], str[j]) == 0)
            {
                flag = 0;
                cnt[i]++;
            }
        if (cnt[i] > max)
        {
            max = cnt[i];
            pos = i;
        }
    }
    for (int i = 1; i < N; i++) //determining if no mode exists
    {
        if (strcmp(str[i + 1], str[i]) == 0)
            k++;
    }
    if (flag || k == N) //all numbers appear same number of times
        cout << "no" << endl;
    else
        cout << str[pos] << endl;
    
    system("pause");
	return 0;
}