#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    /**
     * @brief Constructs a new linked list node.
     *
     * Initializes the node with the given data and sets its next pointer to NULL.
     *
     * @param data Value to be stored in the node.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    /**
     * @brief Constructs a new linked list node with a specified next pointer.
     *
     * @param data Value to be stored in the node.
     * @param next Pointer to the next node in the linked list.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

/**
 * @brief Prints all elements of a singly linked list.
 *
 * Traverses the linked list from the head and prints each node's data.
 *
 * @param head Pointer to the first node of the linked list.
 *
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(1)
 */
void printLL(Node *head)
{
    cout << "in print " << endl;
    Node *pointer = head;
    while (pointer != NULL)
    {
        cout << pointer->data << " ";
        pointer = pointer->next;
    }
    cout << endl;
}

/**
 * @brief Removes consecutive duplicate elements from a sorted linked list.
 *
 * Uses two pointers to track the previous unique node and the current node.
 * When consecutive nodes contain the same value, the current node is removed
 * and its memory is deallocated. The previous pointer remains unchanged so
 * that multiple consecutive duplicates can be removed.
 *
 * //! Assumes the linked list is sorted, so duplicate values are adjacent.
 *
 * @param head Pointer to the first node of the linked list.
 *
 * @note The head pointer is passed by value because this implementation only
 * removes duplicates after the first occurrence of each value.
 *
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(1)
 */
void removeDuplicatesFromLL(Node *head)
{
    Node *prev = NULL;
    Node *pointer = head;
    while (pointer != NULL)
    {
        if (prev != NULL && prev->data == pointer->data)
        {
            Node *temp = pointer;
            pointer = pointer->next;
            prev->next = pointer;
            delete temp;
            continue;
        }
        prev = pointer;
        pointer = pointer->next;
    }
}

/**
 * @brief Creates a sample linked list and removes its consecutive duplicates.
 *
 * Prints the linked list before and after duplicate removal.
 *
 * @return 0 upon successful program execution.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n), for allocating the linked list nodes.
 */
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    head->next = second;

    Node *third = new Node(4);
    second->next = third;

    Node *fourth = new Node(4);
    third->next = fourth;

    Node *fifth = new Node(4);
    fourth->next = fifth;
    Node *sixth = new Node(5);
    fifth->next = sixth;

    printLL(head);
    removeDuplicatesFromLL(head);
    printLL(head);
}