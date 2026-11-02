#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
bool detectLoopInLL(Node *head)
{
    unordered_map<Node *, bool> visitedNodes;
    Node *pointer = head;
    while (pointer->next != NULL)
    {
        if (visitedNodes.count(pointer))
        {
            return true;
        }
        visitedNodes[pointer] = true;
        pointer = pointer->next;
    }
    return false;
}
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    head->next = second;
    Node *third = new Node(3);
    second->next = third;
    Node *fourth = new Node(4);
    third->next = fourth;
    Node *fifth = new Node(5);
    fourth->next = fifth;

    // loop
    fifth->next = second;

    bool loopExistInLL = detectLoopInLL(head);
    cout << "Loop exist in ll: " << loopExistInLL << endl;
}