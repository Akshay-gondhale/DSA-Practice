// https://www.naukri.com/code360/problems/remove-duplicates-from-unsorted-linked-list_1069331?source=youtube&campaign=YouTube_Lovebabbar29thJan&leftPanelTabValue=PROBLEM
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
     * Initializes the node with the given data and links it to the provided node.
     *
     * @param data Value to be stored in the node.
     * @param next Pointer to the next node.
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
 * Traverses the linked list from the head to the last node and prints
 * each node's data.
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
        cout << pointer->data << " ";
        pointer = pointer->next;
    }
    cout << endl;
}

/**
 * @brief Removes duplicate elements from an unsorted singly linked list.
 *
 * Uses an unordered_map to maintain a record of previously encountered
 * values. If a value has already been visited, its corresponding node
 * is removed by adjusting the previous node's next pointer.
 *
 * Preserves the relative order of the first occurrences of all elements.
 *
 * @param head Pointer to the first node of the linked list.
 *
 * @note The implementation assumes an acyclic linked list.
 * The head node is not modified, and duplicate nodes are deallocated.
 *
 * Time Complexity: O(n) average case, where n is the number of nodes.
 * Space Complexity: O(n) for storing visited values in the hash map.
 */
void removeDuplicatesFromLL(Node *head)
{
    unordered_map<int, bool> visitedNodes;
    Node *pointer = head;
    Node *prevPointer = head;
    while (pointer != NULL)
    {
        if (visitedNodes.count(pointer->data))
        {
            //? Preserve the duplicate node's address before moving forward.
            Node *temp = pointer;
            pointer = pointer->next;

            //? Bypass the duplicate node while maintaining the linked list connections.
            prevPointer->next = pointer;

            //? Deallocate the memory occupied by the duplicate node.
            delete temp;
            continue;
        }

        //? Mark the current value as visited so subsequent occurrences can be detected.
        visitedNodes[pointer->data] = true;

        //? Update the previous pointer only when the current node is retained.
        prevPointer = pointer;
        pointer = pointer->next;
    }
}

/**
 * @brief Entry point of the program.
 *
 * Creates an unsorted singly linked list containing duplicate values,
 * prints the original list, removes duplicates, and prints the updated list.
 *
 * Time Complexity: O(n) for printing and removing duplicates on average.
 * Space Complexity: O(n) for dynamically allocated nodes and the auxiliary hash map.
 */
int main()
{
    Node *head = new Node(4);
    Node *second = new Node(5);
    head->next = second;

    Node *third = new Node(2);
    second->next = third;

    Node *fourth = new Node(1);
    third->next = fourth;

    Node *fifth = new Node(5);
    fourth->next = fifth;
    Node *sixth = new Node(6);
    fifth->next = sixth;

    printLL(head);
    cout << "Removing duplicates..." << endl;
    removeDuplicatesFromLL(head);
    printLL(head);
}