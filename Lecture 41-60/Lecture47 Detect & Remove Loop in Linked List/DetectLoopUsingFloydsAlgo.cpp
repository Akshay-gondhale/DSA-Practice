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
     * Initializes a node with the given data and sets its next pointer
     * to NULL.
     *
     * @param data Value to be stored in the node.
     */
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    /**
     * @brief Constructs a new linked list node with a next pointer.
     *
     * Allows creating a node and connecting it to an existing node
     * during initialization.
     *
     * @param data Value to be stored in the node.
     * @param next Pointer to the next node in the linked list.
     */
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

/**
 * @brief Detects whether a linked list contains a cycle.
 *
 * Uses Floyd's Cycle Detection Algorithm (Tortoise and Hare).
 * Two pointers traverse the linked list at different speeds:
 * - Slow pointer moves one node at a time.
 * - Fast pointer moves two nodes at a time.
 *
 * If a cycle exists, both pointers will eventually meet inside the cycle.
 * If the fast pointer reaches NULL, the linked list does not contain a cycle.
 *
 * @param head Pointer to the first node of the linked list.
 * @return true if a cycle exists, otherwise false.
 *
 * @note This algorithm detects cycles without using additional data structures.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
bool detectLoopUsingFlyodInLL(Node *head)
{
    if (head == NULL)
        return false;

    Node *slowPointer = head;
    Node *fastPointer = head;

    while (fastPointer != NULL && fastPointer->next != NULL)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;

        //? If both pointers meet, the fast pointer has completed a cycle.
        if (fastPointer == slowPointer)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Creates a linked list and checks whether it contains a cycle.
 *
 * Constructs a linked list containing five nodes and passes its head
 * pointer to the cycle detection function.
 *
 * @return 0 after successful execution.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
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

    //? Uncomment this statement to create a cycle connecting the last node
    //? back to the second node.
    // fifth->next = second;

    bool loopExistInLL = detectLoopUsingFlyodInLL(head);
    cout << "Loop exist in ll: " << loopExistInLL << endl;
}