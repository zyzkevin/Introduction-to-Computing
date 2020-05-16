#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    double h[100] = {0};
    int n, ans = 0, s[100] = {0}, b[100] = {0}; //s records how many smaller previous, b records how many greater
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];

    s[0] = 1;
    b[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        s[i] = 1;
        for (int j = 0; j < i; j++) //people before
        {
            if (h[i] > h[j] && s[j] + 1 > s[i]) //if previous person is shorter than current
                s[i] = s[j] + 1; //current shorter is +1 shorter than previous
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        b[i] = 1;
        for (int j = n - 1; j > i; j--) //ppl after
        {
            if (h[i] > h[j] && b[j] + 1 > b[i]) //if next person is shorter than current
                b[i] = b[j] + 1; //current shorter is +1 shorter than previous
        }
    }
    for (int i = 0; i < n; i++)
        ans = max(ans, s[i] + b[i] - 1); //deleting repeat
    cout << n - ans;
    system("pause");
	return 0;
}