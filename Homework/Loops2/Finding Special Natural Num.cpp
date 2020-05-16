/*
* &#199;車足&#216;那a℅&#212;豕&#187;那y 
* &#213;&#197;車那&#212;車 1900094801 
* 2019/10/5
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int n; 		//n is user input, digits checks symmetry of base-7 and base-9 (3 means all digits are symmetrical)
	bool flag = false;
	cin >> n;
	for (int i = 342; i > 81; i--) 		//septary 666 - nonary 100
	{
		int septary = 0, nonary = 0, denary; 	//reset septary and nonary
		
		denary = i;
		
		for (int j = 1; j < 1000; j *= 10) 		//converting denary to septary
		{
			septary += denary % 7 * j;
			denary /= 7;
		}
		
		denary = i; 	//reset denary
		
		for (int j = 1; j < 1000; j *= 10) 		//converting denary to nonary
		{
			nonary += denary % 9 * j;
			denary /= 9;	
		}

		if (septary / 100 == nonary % 10) 		//septary symmetrical with nonary
		{
			if (septary % 100 / 10 == nonary / 10 % 10)
			{
				if ( septary % 10 == nonary / 100)
				{
					flag = true; 	//number found, breaking loop
				}
			}
		}
		
		if (flag) 
		{
			switch (n) 		//determining output
			{
				case 1: cout << i << endl; break;
				case 2: cout << septary << endl; break;
				case 3: cout << nonary << endl; break;
				default: break;
			}
			break;
		}
	}
	return 0;
} 
