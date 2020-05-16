/*
* 478-3279
* 张雨泽 1900094801 
* 2019/10/25
*/

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        char str[25];
        cin >> str;
        for (int j = 0; str[j] != 0; j++)
        {
            switch (str[j])
            {
                case '0': num = num * 10; break;
                case '1': num = num * 10 + 1; break;
                case 'A': case 'B': case 'C': case '2': num = num * 10 + 2; break; //converting into number, * 10 to ensure no overlaps
                case 'D': case 'E': case 'F': case '3': num = num * 10 + 3; break;
                case 'G': case 'H': case 'I': case '4': num = num * 10 + 4; break;
                case 'J': case 'K': case 'L': case '5': num = num * 10 + 5; break;
                case 'M': case 'N': case 'O': case '6': num = num * 10 + 6; break;
                case 'P': case 'R': case 'S': case '7': num = num * 10 + 7; break;
                case 'T': case 'U': case 'V': case '8': num = num * 10 + 8; break;
                case 'W': case 'X': case 'Y': case '9': num = num * 10 + 9; break;
                default: break;
            }
            
        }
        cout << setfill('0') << setw(3) << num / 10000 << "-"; //setfill in case there are zeros, / 10000 to get rid of the last 4 digits and insert a -
        cout << setw(4) << num % 10000 << endl; 
    }

    system("pause");
	return 0;
}