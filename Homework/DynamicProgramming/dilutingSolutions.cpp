#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    double con[100] = {0};
    int n, ans = 0, f[100] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> con[i];
    
    f[0] = 1;
    for (int i = 1 ; i < n; i++)
    {
        //first
        f[i] = 1; //assuming no concentration is higher than previous ones
        for (int j = 0; j < i; j++)
        {
            if (con[j] >= con[i] && f[j] + 1 > f[i]) //previous higher concentration exists and its own f is greater than 0
                f[i] = f[j] + 1;
        }
        ans = max(ans, f[i]);
    }
    cout << ans;
    system("pause");
	return 0;
}