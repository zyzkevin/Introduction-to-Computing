/*
* 校门外的树
* 张雨泽 1900094801 
* 2019/9/27
*/

#include <iostream>
using namespace std;

int main()
{
	int  L, M, sum = 0; //declaring variables
	cin >> L >> M;
	int a[10001];

	for (int j = 0; j <= L; j++)
		{
			a[j] = 1; //assuming all trees along every point
		}

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		
		for (int k = start; k <= end; k++)
		{
			a[k] = 0; //removing trees between the given interval
		}
		
	}

	for (int l = L; l >= 0; l--)
		{
			sum += a[l]; //totaling remaining trees
		}
	cout << sum << endl;
	return 0;
} 