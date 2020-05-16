#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, k, a[1000], flag = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == k)
                flag = 1;
        }
    if (flag) cout << "yes";
    else cout << "no";
}