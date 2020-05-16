/*
* œ∞Ã‚(2-) ª≠æÿ–Œ
* ’≈”Í‘Û 1900094801 
* 2019/10/1
*/

#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	char symbol;
	int height, width, isFIll; //declaring varaibles 
	while (true)
	{
		cin >> height; 
		if (height == 0) break; //Exit conditions
		cin >> width >> symbol >> isFIll;

		for (int i = 0; i < height; i++)
		{
			if (i == 0 || i == height - 1 || isFIll == 1) 
			{
				cout << setw(width) << setfill(symbol) << symbol << endl; //First, Last, and unhollow
			}
			else
			{
				cout << symbol << setw(width - 1) << setfill(' ') << symbol << endl; //Hollow inside
			}
		}
	}	
	return 0;
}
