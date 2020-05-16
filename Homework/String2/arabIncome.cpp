/*
* 土豪的乐手日
* 张雨泽 1900094801 
* 2019/10/31
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;


int main()
{
    int i, n, len, j, k = 0; //j records first valid number, k records the pointer in array num[]
    const int max_len = 300;
    unsigned num[max_len], sum[max_len + 1];
    memset(sum, 0, sizeof(sum));
    char str[max_len], prestr[max_len];
    cin >> n;
    while(n--)
    {
        k = 0; //reset k
        memset(num, 0, sizeof(num)); //setting to 0

        cin >> prestr;
        len = strlen(prestr);
        for (j = 0; (prestr[j] < '1' || prestr[j] > '9') && j < len; j++); //finding first non-zero valid num
        strcpy(str, prestr + j);

        len = strlen(str);
        for (j = len - 1; j >= 0; j--)
            num[k++] = str[j] - '0'; //converts string to integer
        for (j = 0; j < max_len; j++)
        {
            sum[j] += num[j]; //adding every digit into sum
            if (sum[j] >= 10) //incrementing digit
            {
                sum[j + 1]++;
                sum[j] -= 10;
            }
        }
    } 
    i = max_len; //detects first nonzero num
    int flag = 1; //detect cout
    while(sum[i] == 0) i--;
    for( ; i >= 0; i--)
    {
        cout << sum[i];
        flag = 0;
    }
    if(flag) cout << 0 << endl;
    cout << endl;    

	return 0;
}

