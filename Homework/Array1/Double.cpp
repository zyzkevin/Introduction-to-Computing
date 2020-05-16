/*
* 两倍
* 张雨泽 1900094801 
* 2019/9/27
*/

#include <iostream>
using namespace std;

int main()
{
    int k;
    int a[15] = {0}, n = 1, i = 0, count = 0; 
    while (cin >> n && n != -1) //looping conditions
    {
        if (n == 0) //Finished entering current set of data
        {
            //Searching for multiples of a[i]
            for (int k = 0; k < i; k++)
            {
                for (int j = 0; j < i; j++)
                    if(2 * a[k] == a[j])
                        count++;
            }
            cout << count << endl;
            //new set of data, resetting values
            i = 0;
            count = 0;
            continue;
        }

        //incrementing and assigning input into array
        a[i] = n;
        i++;
    }
	return 0;
}