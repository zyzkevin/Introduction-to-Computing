/*
* 回数猜想
* 张雨泽 1900094801 
* 2019/11/12
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
void Try(int);
int sum = 0, take[99]; //records steps

int main()
{
	int n;
    cin >> n;
    Try(n);
    cout << sum << endl;
    system("pause");
    return 0;
}

void Try(int remaining)
{
    if (remaining == 0) //no more teeth left
        return;
    for (int attempt = 2; attempt > 0; attempt --) //1 or 2 teeth
    {
        if (remaining < attempt) //not enough teeth left
            continue;
        if (remaining == attempt)
            sum ++;
        else
            Try (remaining - attempt);
    }
    return;    
    
}
