/*
* 集合里的乘法
* 张雨泽 1900094801 
* 2019/11/12
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
bool mult(int);
int sum = 0, k[100] = {1}, flag = 1, product = 1; //records steps
int T, N;

int main()
{
    cin >> T >> N;
    for (int i = 0; i < N; i++)
        cin >> k[i];
    
    if (mult(1))
        cout << "YES";
    else
        cout << "NO";
    system("pause");
    return 0;
}

bool mult(int pos)
{    
    for (int i = pos; i < N; i++)
    {
        if (product * k[i] == T)
            return true;
        if (product * k[i] > T) //if product larger than target
        {
            product = 1; //resetting product
            mult(i + 1);
        }
        else 
        {  
            product = product * k[i]; // reuccirng conditoins
            if (mult(i + 1))
                return true;

        }
    }
    return false;
}
