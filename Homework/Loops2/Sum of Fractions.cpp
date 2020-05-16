/*
* 分数求和 
* 张雨泽 1900094801 
* 2019/10/3
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int old_nu, old_d; 		//old numerator and denominator
	int nu, d; 		//new numerator and denominator
	char sign;
	for (int i = 0; i < n; i++)
	{

		//Extract numerator and denominator	
		scanf("%d%c%d",&nu, &sign, &d);
		
		if (i == 0)
		{
			old_nu = nu;
			old_d = d;
			continue;
		}
		
		//update nu and d
		nu = old_d * nu + old_nu * d;
		d = old_d * d;
		
		//Simplifying fractions
		for (int j = min(d, nu); j > 1 ; j--)
		{
			if (nu % j == 0 && d % j == 0)
			{
				nu /= j;
				d /= j;
			}
		}
		old_nu = nu;
		old_d = d;
	}
	(d == 1) ? printf("%d", nu) : printf("%d/%d", nu, d);
	return 0;
} 
