#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int T, M, v[1000] = {0}, t[1000] = {0}, dp[102][1002] = {{0}}; //dp stores best solution
    cin >> T >> M;
    for (int i = 1; i <= M; i++)
        cin >> t[i] >> v[i];

    //i med and time remaining j
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (j < t[i]) //not enough time
                dp[i][j] = dp[i - 1][j]; //inheriting last item's value
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]); //whether or not to pick the med, depending upon additional value + best value of time before greater than not picking
        }
    } 
    cout << dp[M][T];

    system("pause");
	return 0;
}