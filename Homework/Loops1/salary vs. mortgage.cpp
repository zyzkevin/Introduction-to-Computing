#include <iostream>
using namespace std;
int main()
{
	int M, years = 0; 
	double X, total;
	cin >> X >> M; 
	while (M >= total)
	{
		X *= 1.08;
		total += X;
		M *= 1.1;
		years++;
	}
	if (years <= 100)
	{
		cout << years << endl;
	} else
	{
		cout << "Forget it." << endl;
	}

	
}
