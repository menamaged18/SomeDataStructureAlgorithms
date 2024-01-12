#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *CreateNode(int val)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}
void printList(node *head)
{
    cout << "[";
    while (head->next)
    {
        cout << head->data << ",";
        head = head->next;
    }
    cout << head->data;
    cout << "]";
}

void CombineNode(node *head)
{
    if (head->data == 0)
    {
        head = head->next;
    }
    node *p = head;
    node *temp = head;
    int sum = 0;

    while (temp)
    {
        if (temp->data != 0)
        {
            sum += temp->data;
            temp = temp->next;
        }
        else
        {
            p->data = sum;
            p->next = temp->next;
            temp = temp->next;
            p = temp;
            sum = 0;
        }
    }
    printList(head);
}

int main()
{

    node *head;
    head = CreateNode(0);
    head->next = CreateNode(2);
    head->next->next = CreateNode(5);
    head->next->next->next = CreateNode(4);
    head->next->next->next->next = CreateNode(5);
    head->next->next->next->next->next = CreateNode(0);
    head->next->next->next->next->next->next = CreateNode(2);
    head->next->next->next->next->next->next->next = CreateNode(0);
    CombineNode(head);
    return 0;
}
