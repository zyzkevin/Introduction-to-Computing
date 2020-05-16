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

char c[200], a[200];

int main()
{
    char *p = NULL, *d = NULL;
    char a[100];
    while (cin >> a && a[0] != 'q')
    {
        int flag = 0, flage = 0, pos = 0, posd = 0, sum = 0, flag1 = 0, flagm = 1; //flag whether num is negative, flage whether exponent is negative
        char *t = p = a;
        int len = strlen(a);
        if (*p == '-')
        {
            flag = 1;
            p++;
            t++; //skipping over + and minus sign
        } else if (*p == '+')
        {
            p++;
            t++; //skipping over + and minus sign
        }
        else 
            flagm = 0;
        //pointer t points to non number
        while((*t >= '0' && *t <= '9') || *t == '.')
        {
            t++;
            pos++;
            if (*t == '.')
            { 
                d = t; //point towards decimal point
                posd = pos;
            } else if ((*(t + 1) < '0' || *(t + 1) > '9') && *(t + 1) != '.' && pos + 1 < len - 1) //not last
            {
                flag1 = 1; //non int found
            }
        }
        if (flag1)
        {
            //reading exponent
            if (*(t++) == '-')
            {
                flage = 0;
                t++;
                pos++;
            } else
            {
                pos++;
            }
            int templen = len - pos - 1;
            for (int i = 0; i < templen; i++, t++)
            {
                sum += *t * pow(double(10), double(i));
            }
            if (flage)
            {
                if (len - 4 - posd < sum)
                {
                    char zer = (sum - posd);
                    cout << "0." << setfill('0') << setw(zer);
                    for (int i = 0; i < templen; i++)
                        if (a[i] != '.')
                            cout << a[i];
                } else
                {
                    for (int i = 0; i < posd - sum; i++)
                        cout << a[i];
                    cout << '.';
                    for (int i = posd - sum - 1; i < templen; i++)
                        if (a[i] != '.') cout << a[i];
                }
                cout << endl;
            } else 
            {
                if (sum > templen - posd)
                {
                    for (int i = 0; i < templen; i++)
                        if (a[i] != '.') cout << a[i];
                    cout << setfill('0') << setw(len + sum - (templen - posd));
                } else
                {
                    for (int i = 0; i < templen - posd - sum + 1; i++)
                        if (a[i] != '.') cout << a[i];
                    cout << '.';
                    for (int i =  templen - posd - sum; i < templen; i++)
                        cout << a[i];
                }
                cout << endl;
            } 
        }
        else
        {
            p = a;
            if (flagm) p++;
            if (flag) cout << '-';
            if (len - 2 - posd < 6)
            {
                cout << left << setfill('0') << setw(len - 1 + 6 - len + 2 + posd) << p  << endl;
            }
            else 
                cout << p << endl;
        }
    
    }
}

