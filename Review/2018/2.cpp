#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

bool isPrime(int i)
{
    for (int j = 2; j < i; j++)
        if (i % j == 0) return false;
    return true;
}

int main()
{
    int m;
    cin >> m;
    for (int i = m; i > 4; i--)
    {
        if (isPrime(i) && isPrime(i - 2))
        {
            cout << i - 2 << " " << i;
            break;
        }
    }
}