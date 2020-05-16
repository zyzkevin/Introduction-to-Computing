/*
* 话题焦点
* 张雨泽 1900094801 
* 2019/10/22
*/

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int a[101] = {0}, posts, sender, mentions, person[100][2000] = {0}, temp;
    cin >> posts;

    int max_count = 0, max_loc = 0; 

    for (int i = 0; i < posts; i++)
    {
            cin >> sender >> mentions; //reads first input as sender, second input as number of loops
        for (int j = 0; j < mentions; j++)
        {
            cin >> temp; //current mention
            a[temp]++; //increments counting of mention of each person
            for (int k = 0; k < 2000; k++)
                if (person[temp][k] == 0)
                {
                    person[temp][k] = sender; //adds sender to first none zero
                    break;
                }

            if (max_count < a[temp])
            {
                max_count = a[temp];
                max_loc = temp;
            }
        }
    }

    cout << max_loc << endl;
    sort(person[max_loc], person[max_loc] + max_count);

    for (int i = 0; i < max_count; i++)
    {
        if (person[max_loc][i] == person[max_loc][i + 1]) //skipping duplicates
            continue;
        else if (i == max_count -1) //detecting if last one
        {
            cout << person[max_loc][i];
            break;
        }
        else
            cout << person[max_loc][i] << " ";
    }

    system("pause");
	return 0;
}