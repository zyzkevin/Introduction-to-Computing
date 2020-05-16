/*
* 
* 张雨泽 1900094801 
* 2019/9/27
*/

#include <iostream>
using namespace std;

int main()
{
	int z, q, s, l;
	//通过已知条件，q >= 40, s,z <= 30 , l >= 20
	for (q = 40; q <= 50; q += 10)
	{
		for (z = 10; z <= 30; z += 10)
		{
			for (s = 10; s <= 30; s += 10)
			{
				for (l = 20; l <= 50; l += 10)
				{
					if(q != z && q != s && q != l && z != s && z != l && s != l)
					{
						if (z + q == s + l && z + l > s + q && z + s < q) 
						for (int i = 50; i >= 10; i -= 10)
						{
							if (i == z) cout << "z " << z << endl;
							if (i == q) cout << "q " << q << endl;
							if (i == s) cout << "s " << s << endl;
							if (i == l) cout << "l " << l << endl;
							
						}
					
						
					}
				}
			}
		}
	}
	return 0;
} 
