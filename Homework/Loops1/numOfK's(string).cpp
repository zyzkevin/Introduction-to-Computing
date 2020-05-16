#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
	int m, k, threes; 
	bool isWorks = false;
	cin >> m >> k;
	if (m % 19 == 0)
	{
		string num_str;
		stringstream ss;
		ss << m;
		num_str = ss.str();
		threes = count(num_str.begin(), num_str.end(), '3');
	}
	if (threes == k)
	{
		isWorks = true;
	}
	if (isWorks)
	{
		cout << "YES" << endl;
	} else
	{
		cout << "NO" << endl;
	}

	return 0; 
}
