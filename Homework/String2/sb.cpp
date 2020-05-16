//计算2的N次方 
//秦杰圣 1900094812
//2019.11.5 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
 int n;
 cin >> n;
 unsigned num[10000] = {0};
 num[0] = 1;
 
 if(n == 0)
 {
  num[0] = 1;
 }
 if(n == 1)
 {
  num[0] = 2;
 }
 else
 {
 
  for(int i = 0; i < n; i++)  //进行次方计算 
  {
    for(int m = 0; m < 10000; m++)
    {
        num[m] *= 2;
    }
    for (int m = 0; m < 10000; m++)
    {
            if (num[m] >= 10)
            {
                num[m + 1] += num[m] / 10;
                num[m] = num[m] % 10;
            }
    }

   }
  }

 int x = 9999;
 while(num[x] == 0)
 {
  x--;
 }

 
 for(x; x >= 0; x--)
 {
  cout << num[x];
 }
 system("pause");
 return 0;
}
