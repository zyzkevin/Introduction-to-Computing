/*
* 错误探测
* 张雨泽 1900094801 
* 2019/10/22
*/

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n, a[100][100] = {0};
    while (cin >> n && n != 0)
    {
        int error_count = 0, row_flag = 0, col_flag = 0, flag = 0;

        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
                
        for (int i = 0; i < n; i ++)
        {
            int row_total = 0, col_total = 0;

            for (int j = 0; j < n; j++)
            {
                row_total += a[i][j];
                col_total += a[j][i];
            }
            
            if (row_total % 2 != 0)
            {
                error_count++;
                row_flag = i + 1; //flag stores row num, + 1 in case i = 0
                if (col_total % 2 != 0)
                    flag = 1;
            }
            if (col_total % 2 != 0)
            {
                error_count++;
                col_flag = i + 1; //flag stores col num, + 1 in case i = 0
            }
        }

        if (error_count == 2 && flag == 1)
        {
            cout << "Change bit" << row_flag << col_flag << endl;
        }
        else
            cout << "Corrupt" << endl;

        /*if (row_flag > 0)
            {
                for (int i = 0; i < n; i++)
                {
                    int row_total = 0;
                    a[row_flag - 1][i] = ((a[row_flag - 1][i] == 1) ? 0:1);
                    a[row_flag - 1][i] = ((a[row_flag - 1][i] == 0) ? 1:0);
                    for (int j = 0; j < n; j ++)
                    {
                        row_total += a[row_flag - 1][j];
                    }
                    if (row_total % 2 == 0)
                    {
                        cout << "Change bit" << (row_flag - 1, i) << endl;
                    }
                    else
                    {
                        cout << "Corrupt" << endl;
                        a[row_flag - 1][i] = ((a[row_flag - 1][i] == 1) ? 0:1);
                        a[row_flag - 1][i] = ((a[row_flag - 1][i] == 0) ? 1:0);
                    }
                }  
                
            }

        if (col_flag > 0)
            {
                for (int i = 0; i < n; i ++)
                {
                    int col_total = 0;
                    a[i][col_flag - 1] = ((a[i][col_flag - 1] == 1) ? 0:1);
                    a[i][col_flag - 1] = ((a[i][col_flag - 1] == 0) ? 1:0);
                    for (int j = 0; j < n; j ++)
                    {
                        col_total += a[j][col_flag - 1];
                    }
                    if (col_total % 2 == 0)
                    {
                        cout << "Change bit" << (i, col_flag - 1) << endl;
                    }
                    else
                    {
                        cout << "Corrupt" << endl;
                        a[i][col_flag - 1] = ((a[i][col_flag - 1] == 1) ? 0:1);
                        a[i][col_flag - 1] = ((a[i][col_flag - 1] == 0) ? 1:0);
                    }
                }  
                
            }
        */
        
        if (error_count > 2)
            cout << "Corrupt" << endl;

        if (error_count == 0)
            cout << "OK" << endl;
    }
    system("pause");
	return 0;
}