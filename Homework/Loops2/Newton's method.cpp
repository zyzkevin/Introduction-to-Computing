/*
* Å£¶Ùµü´ú·¨ 
* ÕÅÓêÔó 1900094801 
* 2019/10/3
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//f = x^2 - n
int main()
{
	int n;
	while (cin >> n)
	{
	int counter = 0;
	double newx = 1.0, oldx, f, f1;
	do
	{
		oldx = newx; //New iteration, update x 
		f = oldx * oldx - n; 	//f(oldx)
		f1 = 2 * oldx; 		//f'(oldx)
		newx = oldx - f / f1;
		counter++;
	}
	while (fabs(newx - oldx) >= 1e-6); 		//Error <= 1e-6
	cout << fixed << setprecision(2);
	cout << counter << " " << newx << endl;
	}
	return 0;
} 
