/*
* 二维数组回形遍历
* 张雨泽 1900094801 
* 2019/10/22
*/

#include <iostream>
using namespace std;

int main()
{
    int a[100][100] = {0}, r, c;
    cin >> r >> c;
    int top = 0, bottom = r - 1, right = c - 1, left = 0, i = 0, j = 0, count = 0;    

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
              
    cout << a[i][j] << endl;

    while (count < r * c - 1) // runs less than r* c loops
    {
        //Moving right
        while (j < right && count < r * c - 1)
        {
            j++;
            cout << a[i][j] << endl;
            count++;
        }
        
        top += 1; //incrementing top boundary
        //Moving down
        while (i < bottom && count < r * c - 1)
        {
            i++;
            cout << a[i][j] << endl;
            count++;
        }
        right -= 1; //decrementing right boundary

        //Moving left
        while (j > left && count < r * c - 1)
        {
            j--;
            cout << a[i][j] << endl;
            count++;
        }
        bottom -= 1; //decrementing bottom boundary
        //Moving up
        
        while (i > top && count < r * c - 1)
        {
            i--;
            cout << a[i][j] << endl;
            count++;
        }
        left += 1; //incrementing leftS boundary
    }  
    system("pause");
	return 0;
}