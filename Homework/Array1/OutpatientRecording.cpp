/*
* 门诊计数
* 张雨泽 1900094801 
* 2019/10/15
*/

#include <iostream>
using namespace std;

int main()
{
	int n, temp, a[20] = {0}, arr_t, count = 0, current_time = 60;//Last time = 9.00am, time remaining is 2hrs
	cin >> n;
	//putting arriving times into an array
	for (int i = 0; i < n; i++)
	{
		cin >> arr_t; 
		a[i] = arr_t;
	}

	//bubble sorting
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) //Time remaining >= 10 min
	{
		if (a[i] - current_time > 0)
			current_time = a[i]; //current_time counts the ongoing time when the doctor is busy, if the patient comes later than the current time, current_time = time_arriv
		if (current_time > 170)
			break;
		current_time += 10;
		count++;
	}

	cout << count << endl;
	return 0;
}