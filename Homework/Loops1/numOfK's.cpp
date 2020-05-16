#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int m, k, threes; 
	bool isWorks = false;
	cin >> m >> k;
	if (m % 19 == 0)
	{
		for (int i = 0; i < 6; i++)
		{
			m /= (int)(pow(10.0, i));
			for (int j = 0; j < 6; j++)
			{
				if (m % (int)(pow(10.0, (5-j)))==3)
				{
					threes++;
				}
			}
		}
	}
	if (threes == k)
	{
		isWorks = true;
	}
	if (isWorks)
	{
		cout << "YES" << endl;
	} else
	{
		cout << "NO" << endl;
	}

	return 0; 
}
