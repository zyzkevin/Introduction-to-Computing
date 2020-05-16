#include <iostream>

using namespace std;

struct stu
{
        char ID;
        double GPA;
        int place;
}stu[16];

int main()
{
    int N;
    
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
        {
            if (stu[i].GPA < stu[j].GPA )
                stu[i] = ;
        }
      
    
}