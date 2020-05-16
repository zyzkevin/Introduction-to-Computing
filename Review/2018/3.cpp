#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

bool isPrime(int i)
{
    for (int j = 2; j < i; j++)
        if (i % j == 0) return false;
    return true;
}
bool isSquare(int x)
{
    for (int i = 1; i < x; i++)
    {
        if(i * i == x)
        return true;
    }
    return false;
}

bool contains13(int x)
{
    for (int i = 1; i <= 9; i++)
}

int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    int first3, last3;
    for (int i = n; i < m; i++)
    {
        first3 = i / 1000000;
        last3 = i % 1000;
        if (isPrime(first3))
        {
            if (isSquare(last3))
            {
                if (!contains13(i))
                    cnt++;
            }
        }
    }
    cout << cnt;
}