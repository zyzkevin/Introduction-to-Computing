/*
* 紧急措施
* 张雨泽 1900094801 
* 2019/10/26
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    char email[50];
    int N, flag = 1;
    cin >> email >> N;
    for (int i = 0; i < N; i++)
    {
        char str[3][50];
        cin >> str[0] >> str[1] >> str[2];

        if (strncmp (str[2], email, strlen(email)) == 0) //if this email belongs to user
        {
            flag = 0;
            for (int j = 0; str[1][j] != 0; j++)
            {
                if (str[1][j] >= 'A' && str[1][j] <= 'Z') //if uppercase
                    str[1][j] += 32;
                else if (str[1][j] >= 'a' && str[1][j] <= 'z') //if lowercase
                    str[1][j] -= 32;
            } 
        cout << str[0] << " " << str[1] << endl; //output username and password
        
        } 
        
    }
    if (flag)
        cout << "empty" << endl;
    
    system("pause");
	return 0;
}