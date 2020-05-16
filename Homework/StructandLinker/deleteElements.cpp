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

linker *dele(linker *head, int k)
{
    linker *temp, *ahead;
    if (head -> num == k)
    {
        temp = head;
        head = head -> next;
        delete temp;
        return (head);
    }
    temp = head;
    while (temp != NULL && temp -> num != k)
    { 
        ahead = temp; temp = temp -> next;
    }
    if (temp == NULL)
        return head;
    else
    {
        ahead -> next = temp -> next;
        delete temp;
    }
    return head;
}

void showList(linker *);
int main()
{
    linker *head;
    int k;
    head = create();
    cin >> k;
    for (int i = 0; i < 2000; i++)
    {
        head = dele(head, k);
    }

    showList(head);
    if (head == NULL)
    cout << 0;

}

linker *create()
{
    linker *ahead, *temp, *head = NULL;
    int k, n;
    cin >> n;      
    cin >> k;
    n--;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
    while(n--)
    {
        temp = new linker;
        temp -> num = k;
        if (head == NULL)
            head = temp;
        else
            ahead -> next = temp;
        ahead = temp;
        cin >> k;
    }
    if (head != NULL)
        temp -> next = NULL;
    return head;
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

