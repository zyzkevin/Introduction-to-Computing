/*
* 计算鞍点
* 张雨泽 1900094801 
* 2019/10/18
*/

#include <iostream>
using namespace std;

int main()
{
    int a[5][5], flag = 0, row_max[5] = {0}, column_min[5]; //two arrays listing the largest num in row and the smallest num in column, respectively

    for (int i = 0; i < 5; i++)
    {    
        for (int j = 0; j < 5; j++)
        {    
            cin >> a[i][j];
            if (a[i][j] > row_max[i])
                row_max[i] = a[i][j]; 
            if (a[i][j] < column_min[j])
                column_min[j] = a[i][j];
        }
        
    }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (row_max[i] == column_min[j])
            { 
                cout << i + 1 << " " << j + 1 << " " << column_min[j] << endl; //+ 1 because row and column both start with 0
                flag = 1;
            }
    if (flag == 0)
        cout << "not found" << endl;
    system("pause");
	return 0;
}