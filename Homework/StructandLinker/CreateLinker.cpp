/*
张雨泽 1900094801
花生问题
12/23
*/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct linker
{
    int num; 
    linker *next;
};
linker *create();
void mysort(linker *head);
void showList(linker *);
int main()
{
    linker *head;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        head = create();
        mysort(head);
        showList(head);
    }
    system("pause");
}
linker *create()
{
    linker *ahead, *temp, *head = NULL;
    int k;
    char ch;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    while(cin >> k)
    {
        temp = new linker;
        temp -> num = k;
        if (head == NULL)
            head = temp;
        else
            ahead -> next = temp;
        ahead = temp;
        ch = cin.get();
        if (ch == '\n') //new line
            break;
    }
    if (head != NULL)
        temp -> next = NULL;
    return head;
}
void mysort(linker *head)
{
    linker *temp, *ahead, *tail = NULL;
    while (head != tail)
    {
        ahead = head; temp = ahead -> next;
        while(temp != tail)
        {
            if (ahead -> num > temp -> num)
            {
                int t = ahead -> num;
                ahead -> num = temp -> num;
                temp -> num = t;
            }
            ahead = temp; temp = temp -> next; 
        }
        tail = ahead;
    }
}
void showList(linker *head)
{
    linker *temp;
    if (head != NULL)
    {
        temp = head;
        do
        {
            if (temp -> next != NULL)
                cout << temp -> num << " ";
            else
                cout << temp -> num;
            temp = temp -> next;
        } while (temp != NULL);
    }
    cout << endl;
}

