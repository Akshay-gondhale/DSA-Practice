#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    /**
     * @brief Constructs a new node with the given data.
     *
     * Initializes the node and sets its next pointer to NULL.
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
     * @brief Constructs a new node with data and a next pointer.
     *
     * Initializes the node with the specified data and links it to
     * the provided next node.
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
 * @brief Prints all elements of a circular singly linked list.
 *
 * Starts from the head node and traverses the list until it reaches
 * the head again, ensuring that each node is printed exactly once.
 *
 * @param head Pointer to the first node of the circular linked list.
 *
 * @note Assumes the linked list is non-empty and properly circular.
 *
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(1)
 */
void printLL(Node *head)
{
    Node *pointer = head;
    cout << pointer->data << " ";
    pointer = pointer->next;
    while (pointer != NULL && pointer != head)
    {
        cout << pointer->data << " ";
        pointer = pointer->next;
    }
    cout << endl;
}

/**
 * @brief Finds the middle node of a circular singly linked list.
 *
 * Uses the Slow and Fast Pointer technique (Floyd's approach).
 * The slow pointer moves one node at a time, while the fast pointer
 * moves two nodes at a time.
 *
 * Traversal stops when the fast pointer reaches the last node or
 * when its next node is the last node, depending on the list length.
 *
 * @param head Pointer to the first node of the circular linked list.
 * @return Pointer to the middle node. For an even-sized list, returns
 * the first middle node.
 *
 * @note Assumes the circular linked list contains at least one node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Node *findMidOfCircularLL(Node *head)
{
    Node *slowPointer = head;
    Node *fastPointer = head;
    while (fastPointer->next != head && fastPointer->next->next != head)
    {
        //? Move slow by one node and fast by two nodes to locate the middle.
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    return slowPointer;
}

/**
 * @brief Splits a circular linked list into two circular linked lists.
 *
 * Finds the middle node and uses it to divide the original list into
 * two halves. The first half starts at the original head, while the
 * second half starts at the node immediately following the middle.
 *
 * Both resulting lists are made circular by connecting their respective
 * last nodes back to their own head nodes.
 *
 * @param head Pointer to the first node of the original circular linked list.
 * @return A vector containing two head pointers:
 *         - Index 0: Head of the first circular linked list.
 *         - Index 1: Head of the second circular linked list.
 *
 * @note For an even-sized list, both resulting lists contain an equal
 * number of nodes. For an odd-sized list, the first list contains one
 * additional node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) auxiliary space, excluding the returned vector.
 */
vector<Node *> splitCircularLLInTwo(Node *head)
{
    Node *mid = findMidOfCircularLL(head);
    Node *secondListHead = mid->next;

    //? Close the first half by connecting its last node back to the original head.
    mid->next = head;

    Node *pointer = secondListHead;

    //? Locate the last node of the second half before reconnecting it circularly.
    while (pointer->next != secondListHead && pointer->next != head)
    {
        pointer = pointer->next;
    }

    //? Complete the second circular list by connecting its last node to its own head.
    pointer->next = secondListHead;

    vector<Node *> splittedList = {head, secondListHead};
    return splittedList;
}

/**
 * @brief Entry point of the program.
 *
 * Creates a circular singly linked list containing six nodes, prints
 * the original list, splits it into two circular linked lists, and
 * prints both resulting lists.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) for dynamically allocated nodes and the returned vector.
 */
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
    Node *sixth = new Node(6);
    fifth->next = sixth;
    sixth->next = head;

    printLL(head);
    cout << "Splitting circular LL in two... " << endl;
    vector<Node *> splittedLists = splitCircularLLInTwo(head);
    for (int i = 0; i < splittedLists.size(); i++)
    {
        printLL(splittedLists[i]);
    }
}