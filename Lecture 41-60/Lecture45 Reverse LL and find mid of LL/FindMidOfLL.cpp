#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
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
//? There are two ways to solve this:
//? 1. Iterative approach: Find the complete length, divide it by 2,
//?    and traverse again to reach the middle node.
//? 2. Fast and slow pointer approach: Move the fast pointer twice as
//?    fast as the slow pointer so that slow reaches the middle.
//*
//* The implementation below uses the second approach.
/**
 * @brief Finds and returns the middle node of a singly linked list.
 *
 * Uses the fast and slow pointer technique. The fast pointer moves two
 * nodes at a time while the slow pointer moves one node at a time.
 * By the time the fast pointer reaches the end, the slow pointer reaches
 * the middle of the linked list.
 *
 * @param head Pointer to the head node of the linked list.
 * @return Pointer to the middle node of the linked list.
 *
 * @note For an even-length linked list, this implementation returns the
 *       second middle node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *fastPointer = head->next;
    Node *slowPointer = head;

    while (fastPointer != NULL)
    {
        //? If fastPointer is at the last node, moving slowPointer once
        //? more places it at the second middle node for an even-length list.
        if (fastPointer->next == NULL)
        {
            fastPointer = NULL;
        }
        else
        {
            //? Move fastPointer two nodes at a time while slowPointer
            //? advances by only one node.
            fastPointer = fastPointer->next->next;
        }

        slowPointer = slowPointer->next;
    }

    return slowPointer;
}

void printList(Node *head)
{

    cout << "[";
    Node *printPointer = head;

    while (printPointer->next != NULL)
    {
        cout << printPointer->data;
        if (printPointer->next != NULL)
        {
            cout << ", ";
        }
        printPointer = printPointer->next;
    }
    cout << printPointer->data;
    cout << "]" << endl;
}
int main()
{
    Node head = Node(1);
    Node node1 = Node(2);
    head.next = &node1;
    Node node2 = Node(3);
    node1.next = &node2;
    Node node3 = Node(4);
    node2.next = &node3;

    printList(&head);

    Node *newHead = findMiddle(&head);
    cout << "Mid is: " << newHead->data << endl;
}