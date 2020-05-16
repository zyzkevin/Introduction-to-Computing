/*
* 集合里的乘法
* 张雨泽 1900094801 
* 2019/11/12
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int m, n, cnt = 0, j = 0, flag = 1, temp = 1; //m: number of apples, n: plates, cnt: successful ways, temp is current plate

void place(int count)
{    
    for (int i = temp; i <= m; i++) //giving apples, i is current plate #apples
    {
        if (count + i > m) //加上之后超过了，说明该方案不可行，直接刷掉。 
            break; 
        if (count + i == m) //all given
        {
            cnt++;
            if (cnt <= n)
            {
                j++;
                cnt--; //retrieving
            }
            else //not enough plates
            {
                cnt--;
                break;
            }
        }
        else //placing apples
        {
            temp = i; //updating number of apples
            cnt++; 
            place(count + i); //recurring
            cnt--;
        }
            
    }
   
}

int main()
{
    

    int t;
    cin >> t;
    while (t--)
    {
        temp = 1;
        cnt = 0;
        j = 0;
        cin >> m >> n;
        place(0);
        cout << j << endl;
    }
    system("pause");
}
