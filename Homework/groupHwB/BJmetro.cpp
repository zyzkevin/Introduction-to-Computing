#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, m;
    double sum;
    cin >> n >> m;
    if (m <= 6) sum = 3;
    else if (m <= 12) sum = 4;
    else if (m <= 22) sum = 5;
    else if (m <= 32) sum = 6;
    else if (m > 32) sum = (m + 20 - 1 - 32) / 20 + 6;

    if (n >= 100 && n < 150) sum *= 0.8;
    else if (n >= 150 && n < 400) sum *= 0.5;
    cout << fixed << setprecision(2) << sum;

}