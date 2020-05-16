/*
* ËÄ´óºú 
* ÕÅÓêÔó 1900094801 
* 2019/9/27
*/

#include <iostream>
using namespace std;

int main()
{
	//Initialize variables
	int A, B, C, D, a, b, c ,d;
	//run 4 loops for each combo of a,b,c,d
	for (a = 1; a <= 4; a++)
	{
		for (b = 1; b <= 4; b++)
		{
			for (c = 1; c <= 4; c++)
			{
				for (d = 1; d <= 4; d++)
				{
					//diff. lake sizes
					if (a != b && b != c && c != d && d != a && a != c && b!= d)
					{
						//totaling the sum of correct phrases (must be 1)
						A = (b == 1) + (d == 4) + (a == 3);
						B = (d == 1) + (b == 4) + (c == 3) + (a == 2);
						C = (b == 3) + (d == 4);
						D = (a == 1) + (c == 4) + (d == 2) + (b == 3);
						if (A == 1 && B == 1 && C == 1 && D == 1)
						{
							cout << a << endl << b << endl << c << endl << d << endl;
						}
					}
				}
			}
		} 
	}
	
	return 0;
} 
