#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Represents a node in a doubly linked list.
 *
 * Each node stores an integer value and maintains pointers to both
 * its previous and next nodes.
 */
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    /**
     * @brief Default constructor.
     *
     * Initializes the node with data 0 and NULL pointers.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    /**
     * @brief Constructs a node with the given data.
     *
     * Initializes both previous and next pointers to NULL.
     *
     * @param data Value to be stored in the node.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    /**
     * @brief Constructs a node with data and existing adjacent nodes.
     *
     * @param data Value to be stored in the node.
     * @param next Pointer to the next node.
     * @param prev Pointer to the previous node.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

/**
 * @brief Prints the nodes of a doubly linked list with their addresses.
 *
 * Traverses the list from the head and displays each node's previous
 * pointer, address, data, and next pointer.
 *
 * @param head Pointer to the first node of the linked list.
 *
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(1)
 */
void printLL(Node *head)
{
    Node *pointer = head;
    while (pointer != NULL)
    {
        pointer = pointer->next;
    }
    cout << endl;
}

/**
 * @brief Removes consecutive duplicate values from a sorted doubly linked list.
 *
 * Uses two pointers to identify and skip duplicate nodes. When consecutive
 * nodes contain the same value, the current node is disconnected by updating
 * the next pointer of the previous unique node and the previous pointer
 * of the next node.
 *
 * //! Assumes the doubly linked list is sorted in ascending order.
 *
 * @param head Pointer to the first node of the linked list.
 * @return Pointer to the head of the updated doubly linked list.
 *
 * @note Removed nodes are disconnected but not deallocated because this
 * implementation does not manage dynamic memory.
 *
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(1)
 */
Node *removeDuplicates(Node *head)
{
    Node *prev = NULL;
    Node *pointer = head;
    while (pointer != NULL)
    {
        if (prev != NULL && prev->data == pointer->data)
        {
            pointer = pointer->next;

            //? Maintain the backward connection of the next node after skipping the duplicate.
            if (pointer != NULL)
            {
                pointer->prev = prev;
            }

            //? Connect the previous unique node directly to the next remaining node.
            prev->next = pointer;
            continue;
        }
        prev = pointer;
        pointer = pointer->next;
    }
    return head;
}

/**
 * @brief Creates a sample doubly linked list and removes its duplicates.
 *
 * Prints the linked list before and after removing consecutive duplicates.
 *
 * @return 0 upon successful program execution.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1), excluding the statically allocated list nodes.
 */
int main()
{
    Node head = Node(1);
    Node second = Node(2);
    Node third = Node(5);
    Node fourth = Node(5);
    Node fifth = Node(5);

    head.next = &second;

    second.next = &third;
    second.prev = &head;

    third.next = &fourth;
    third.prev = &second;

    fourth.next = &fifth;
    fourth.prev = &third;

    fifth.prev = &fourth;
    printLL(&head);
    cout << endl;
    cout << "Removing duplicated..." << endl;
    removeDuplicates(&head);
    cout << endl;
    printLL(&head);
}