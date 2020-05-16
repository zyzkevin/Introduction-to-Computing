#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
void mysort(char *q[], int n)
{
    char *t, temp[200];
    for (int i = 0; i < n - 1; i++)
    {
        t = q[i];
        for (int j = i; j < n - 1; j++)
        {
            if (strcmp(t, q[j]) < 0)
            {
                strcpy(temp, t);
                strcpy(t, q[j]);
                strcpy(q[j], temp);
            }
        }
    }
    return;
}

int main()
{
    int t, n;
    cin >> t;
    char *p[200];

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        mysort(p, n);
        for (int i = 0; i < n; i++)
            cout << p[i] << endl;
        cout << endl;
    }
    return 0;

}