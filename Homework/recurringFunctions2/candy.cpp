/*
* 幼儿园分糖
* 张雨泽 1900094801 
* 2019/11/18
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int n, cnt = 0, Max = 0, like[20][20] = {0}, candy[20] = {0}, take[20] = {0}, flag = 1, candyCount;  //take requires person p took cn, and candy records if candy still avaliable

void share(int p) //pth person, and cn candy number
{    
    if (p != n - 1) //recurring conditions
    { 
        for(int cn = 0; cn < candyCount; cn++) 
        { 
            if(like[p][cn] == 1 && (candy[cn] == 0)) //candy avaliable
            { 
                cnt++;
                candy[cn] = 1; //giving candy
                share(p + 1); 
                candy[cn] = 0; //retrieving candy
                cnt--; //retrieving
            } 
        } 
        share(p + 1); //skipping over taken candy
    } 

    if (p == n - 1) //if last person
    {
        for (int cn = 0; cn < candyCount; cn++)
        {
            if (like[p][cn] == 1 && (candy[cn] == 0))
            {
                cnt++;
                flag = 0;
                if(cnt > Max) Max = cnt; // p + 1 because started counting from 0
                
                if (flag == 0)
                {
                    cnt--; //retrieving skipped candies
                    flag = 1; //resetting flag
                }
            }
        }
    }
}

int main()
{
    int f, k, temp;
    cin >> n >> candyCount;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> temp;
            like[i][temp - 1] = 1;
        }

    }
    share(0);
    cout << Max;
    system("pause");
    return 0;
}


