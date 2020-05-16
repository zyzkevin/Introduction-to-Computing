/*
张雨泽 1900094801
花生问题
12/23
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int M, N, K, field[21][21] = {0}, totalTime = 0, peanutCnt = 0, posi = 0, posj; //m row, n columns, k time
        cin >> M >> N >> K;
        for (int i = 1; i <= M; i++)
            for(int j = 1; j <= N; j++)
                cin >> field[i][j];
        while (totalTime < K)
        {
            int max = 0, maxi = 0, maxj = 0;
            for (int i = 1; i <= M; i++)
                for(int j = 1; j <= N; j++)
                    if (field[i][j] > max)
                    {
                        max = field[i][j];
                        maxi = i;
                        maxj = j;
                    }
            if (max == 0) //no more peanuts
                break;
            if (posi == 0) 
                posj = maxj; //walks from road to largest peanut column, then go into field
            if (totalTime + maxi + 1 + abs(maxi - posi) + abs(maxj - posj) <= K) //if enough time to walk to largest peanut and back
            {
                totalTime += abs(maxi - posi) + abs(maxj - posj) + 1; //+1 for picking
                posi = maxi;
                posj = maxj;
                peanutCnt += field[maxi][maxj];
                field[maxi][maxj] = 0;
            }
            else break;
        }
        cout << peanutCnt << endl;
    }

}