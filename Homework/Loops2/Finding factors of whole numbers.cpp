/*
* 整数的质因子分解
* 张雨泽 1900094801 
* 2019/9/27
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num;
	cin >> num;
	for (int i = 2; i <= num; i++)
	{
		int factor = 0;
		if (num % i == 0) //factor found
		{
			factor = i;	
			//first test if is Prime
			//for loop and factor finder 
			bool factor_counter = false;
			for (int j = 2; j <= sqrt(factor); j += 2)
			{
				if (factor % j == 0) 
				{
					factor_counter = true; 
					break; 
				}
			}
			if (!factor_counter) //factor is prime
			{
				for (int k = num / factor; k > 0; k--)
					{
						int factor_to_kth= int((pow(double(factor), double(k))));
						if (num % factor_to_kth == 0) 
						{
							cout << i << " " << k << endl; 
							num = num / (factor_to_kth);
						}
					}
			}
		}
	}
	return 0;
} 
