/*
* 细菌的战争 
* 张雨泽 1900094801 
* 2019/9/27
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int malic, benign;
		int hours = 0;
		cin >> malic >> benign;
		do
		{
			//calculations
			if (malic >= 1000000)
			{
				malic = 1000000;
			}
			malic -= benign;
			malic *= 2;
			benign *= 1.05;
			hours ++;
		} while (malic > 0);
		
		cout << hours << endl;
	}
	return 0;
} 
