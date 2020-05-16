/*
* 回数猜想
* 张雨泽 1900094801 
* 2019/11/12
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
bool reverse (int);
int reverse1(int);
int cnt = 0;
int main()
{
	int n;
    cin >> n;
    if (reverse(n)) // if is reverse
        cout << "Y" << endl;
    else
        cout << "N";
    
}

bool reverse (int i )
{
    //recurring conditions
    if (i == reverse1(i))
        return true;
    //output calculations
    cout << i << "+" << reverse1(i) << '=' << i + reverse1(i) << endl;
    for (int j = 0; j < 7; j++)
    {
        //for loop until conditions become true
        if (reverse(i + reverse1(i)))
            return true;
    }
    return false;
}

int reverse1 (int i)
{
    //reversing num
    int ren = 0, r;
    while (i != 0)
    {
        r = i % 10;
        ren = ren * 10 + r;
        i /= 10;
    }
    return ren;
}