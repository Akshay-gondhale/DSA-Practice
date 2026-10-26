#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
bool isCircularLL(Node<int> *head)
{
    Node<int> *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
        return true;
    return false;
}
int main()
{
    Node<int> head = Node(1);
    Node<int> node1 = Node(2);
    head.next = &node1;
    Node<int> node2 = Node(3);
    node1.next = &node2;
    node2.next = &head;

    bool isCircular = isCircularLL(&head);
    if (isCircular)
    {
        cout << "Given LL is circular" << endl;
    }
    else
    {
        cout << "Given LL is not circular" << endl;
    }
}