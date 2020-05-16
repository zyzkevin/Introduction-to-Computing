/*
* RMB Pay
* 张雨泽 1900094801 
* 2019/10/31
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

void isFactor(int, int), output(int);
int isBigM(int);

int main()
{
    int y, m ,d, leap = 0;
    scanf("%d-%d-%d",&y,&m,&d);
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        leap = 1;
    switch (d)
    {
        case 30:
        {
            if (isBigM(m))
                d++;
            else
            {
                m++; d = 1;
            }
        } break;
        case 31: case 29:
        {
            m++; d = 1;
        } break;
        case 28:
        {
            if (leap && m == 2)
                d++;
            else
            {
                m++; d = 1;
            }
        } break;

        default: d++;
    }
    if (m == 13)
    {
        m = 1; d = 1; y++;
    }
    printf("%d-%02d-%02d\n", y, m, d);
}

int isBigM(int i)
{
    if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        return 1;
    else return 0;
}