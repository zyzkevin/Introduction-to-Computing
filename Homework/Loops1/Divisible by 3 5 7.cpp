#include <iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int factors = 0; 	//0=no factors; 3=3; 5=5; 7=7; 8=3,5; 10=3,7; 12=5,7; 15=3,5,7;
	if (num%3 == 0) factors+=3; 
	if (num%5 == 0) factors+=5; 
	if (num%7 == 0) factors+=7; 
	
	//sum up all the factors and use switch to determine which and how many factors
	switch (factors)
	{
		case 3: cout << 3; break; 
		case 5: cout << 5; break; 
		case 7: cout << 7; break; 
		case 8: cout << 3 << " " << 5; break; 
		case 10: cout << 3 << " " << 7; break; 
		case 12: cout << 5 << " " << 7; break; 
		case 15: cout << 3 << " " << 5 << " " << 7; break; 
		default: cout << "n"; break;
	}
	return 0;
}
