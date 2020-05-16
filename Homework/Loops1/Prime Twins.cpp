#include <iostream>
#include <cmath> 
using namespace std;

/*
Input an integer
Checks if input has factors
Outputs boolean, true if prime, false if not prime
*/
bool isPrime(int input) 
{
	int factors = 0;
	for (int i = 2; i < input-1; i++)
	{
		if (input % i == 0)
		{
			factors ++;
		}
	}
	if (factors == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int num;
	cin >> num;
	for (int i = num; i > 5; i--)
	{
		if (isPrime(i))
		{
			if (isPrime(i-2)) 	//Check if i-2 is also prime
			{
				cout << i-2 << " " << i << endl;
				break;
			}
		}
	}
	return 0;	
}
