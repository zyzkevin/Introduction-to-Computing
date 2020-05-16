#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int batteries;
	while (cin >> batteries)
	{
		int max_life = 0;
		double total_life = 0.0;			//sum of all battery lives	
		for (int i = 0; i < batteries; i++) //for loop counting total battery life and finding the max_life
		{
			int batt_life;
			cin >> batt_life;			//input current battery life
			total_life += batt_life;
			
			if (batt_life > max_life) 
			{
				max_life = batt_life;	 //Update max_life
			}
		}
		
		if (max_life > total_life - max_life)
		{
			cout << fixed << setprecision(1);
			cout << total_life - max_life << endl; //电量没用完 
		} 
		else
		{
			cout << total_life / 2.0 << endl; //output average battery life
		}
	}
	return 0;
} 
