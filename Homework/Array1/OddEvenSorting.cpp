/*
* 整数奇偶排序
* 张雨泽 1900094801 
* 2019/10/15
*/

#include <iostream>
using namespace std;

void moveFront(int j);
int a[10], temp;

int main()
{

    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }

	//bubble sorting
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
            int next = a[j + 1], current = a[j];
            //move odd forward
            if (current % 2 == 0 && next % 2 == 1)
                moveFront(j);

            //Both even and current is larger, move forward
            else if (current % 2 == 0 && next % 2 == 0 && current > next)
                moveFront(j);
            //move odd and smaller forward
            else if (current % 2 == 1 && next % 2 == 1 && current < next)
                moveFront(j);
		}
	}

    for (int i = 0; i < 10; i++)
    {
        if (i != 9)
            cout << a[i] << " ";
        else
            cout << a[i];
    }
	return 0;
}

void moveFront(int j) //Move j to the front
{
    temp = a[j];
	a[j] = a[j + 1];
	a[j + 1] = temp;
}