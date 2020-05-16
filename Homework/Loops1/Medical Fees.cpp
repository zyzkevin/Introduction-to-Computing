#include <iostream>
using namespace std;
int main()
{
	int n;
	double feeTotal = 0.00;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double fee;
		int fee_range;
		cin >> fee;
		fee_range = fee/100 	//
		switch (fee_range)
		{
			case 0: fee = 0; break;
			case 1: fee *= 0.1; break;
			case 2: fee *= 0.3; break;
			case 3: fee *= 0.3; break;
			case 4: fee *= 0.3; break;
			default: fee *= 0.5; break;
		}
		feeTotal += fee; 	//
	}
	printf("%.2lf", feeTotal);
	cout << endl;
	return 0;
} 
