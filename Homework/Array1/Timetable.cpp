/*
* 辉辉的日程表
* 张雨泽 1900094801 
* 2019/10/11
*/

#include <iostream>
using namespace std;

int main()
{
	int n, a[20] = {0};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		int t1, t2;
		cin >> t1 >> t2;
		t1 -= 9; //Starts at 9, which is 0, ends at 21 which is 12
		t2 -= 9;
		for (int j = t1; j < t2; j++)
		{
			if (a[j] != 1 && a[t2 - 1] != 1) //check if start and end time are both occupied
				a[j] = 1; //time available, making reservation
			else
			{
				flag = 1;
				break; //break if time occupied
			}
		}

		if (flag == 0)
		cout << "Y" << endl;
		else
		cout << "N" << endl;
	}
	system("pause");
	return 0;
} 
