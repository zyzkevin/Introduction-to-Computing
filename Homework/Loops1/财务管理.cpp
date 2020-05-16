#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double balance_remaining, sum;
	for (int i=0; i<12; i++)
	{
		cin >> balance_remaining;
		sum += balance_remaining;
	}
	sum /= 12.00;
	cout << "fixed";
	cout << setprecision(2) << '$' << sum;
	return 0;
}