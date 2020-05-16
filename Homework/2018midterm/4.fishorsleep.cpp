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
    int totaldays = 0, years, months, days, leap = 0;
    cin >> years >> months >> days;
    years -= 1990;
    totaldays = years * 365;
    leap = (years % 4 == 0);
    for (int i = 1; i < months; i++)
        switch (i)
        {
        case 2: totaldays += 28 + leap; break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: totaldays += 31; break;
        default: totaldays += 30; break;
        }
    totaldays+= days;
    if (totaldays % 5 <= 3 && totaldays%5 != 0)
        cout << "fishing";
    else
    {
        cout << "sleeping";
    }
    

    system("pause");
	return 0;
}

