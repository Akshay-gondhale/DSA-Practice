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

/**
 * @brief Detects whether a linked list contains a cycle.
 *
 * Uses Floyd's Cycle Detection Algorithm (Tortoise and Hare).
 *
 * - Slow pointer moves one step at a time.
 * - Fast pointer moves two steps at a time.
 *
 * If a cycle exists, the fast pointer eventually catches up with
 * the slow pointer inside the cycle.
 *
 * @param head Pointer to the first node of the linked list.
 * @return true if a cycle exists, otherwise false.
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

        //? Both pointers meeting confirms the existence of a cycle.
        if (fastPointer == slowPointer)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Finds the collision point of slow and fast pointers.
 *
 * Uses Floyd's Cycle Detection Algorithm and returns the node
 * where both pointers meet.
 *
 * @param head Pointer to the first node of the linked list.
 * @return Pointer to the collision node, or NULL if no cycle exists.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
Node *flyodAlgo(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slowPointer = head;
    Node *fastPointer = head;

    while (fastPointer != NULL && fastPointer->next != NULL)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;

        if (fastPointer == slowPointer)
        {
            return slowPointer;
        }
    }

    //? No collision means the linked list does not contain a cycle.
    return NULL;
}

/**
 * @brief Detects the starting node of a cycle and removes the loop.
 *
 * First, finds the collision point using Floyd's algorithm.
 * Then, resets one pointer to the head and moves both pointers
 * one step at a time until they meet at the cycle's starting node.
 *
 * Finally, disconnects the previous node from the cycle entry.
 *
 * Special case:
 * If the cycle starts at the head, both pointers already meet at
 * the head after resetting. In this case, traverse the cycle to
 * find its last node and disconnect it.
 *
 * @param head Pointer to the first node of the linked list.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
void detectIntersectionAndRemoveLoop(Node *head)
{
    if (head == NULL)
        return;

    Node *slowPointer = head;
    Node *floydIntersection = flyodAlgo(head);

    //? No cycle exists, so there is nothing to remove.
    if (floydIntersection == NULL)
        return;

    //? Special case: The cycle starts at the head.
    if (slowPointer == floydIntersection)
    {
        //? Find the last node inside the cycle.
        while (floydIntersection->next != slowPointer)
        {
            floydIntersection = floydIntersection->next;
        }

        //? Disconnect the last node from the head.
        floydIntersection->next = NULL;
        return;
    }

    //? Find the cycle entry by moving both pointers one step at a time.
    while (slowPointer->next != floydIntersection->next)
    {
        slowPointer = slowPointer->next;
        floydIntersection = floydIntersection->next;
    }

    //? Both pointers are now at the node immediately before the cycle entry.
    //? Disconnect it to remove the loop.
    floydIntersection->next = NULL;
}

/**
 * @brief Creates a linked list, introduces a cycle, and removes it.
 *
 * Demonstrates Floyd's cycle detection and loop removal algorithms.
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

    //? Create a cycle by connecting the last node back to the second node.

    //? Test 1: Cycle starts at an intermediate node.
    fifth->next = second;

    //? Test 2: Cycle starts at the head.
    // fifth->next = head;

    //? Test 3: No cycle.
    // fifth->next = NULL;

    //? Test 4: Self-loop.
    // fifth->next = fifth;

    bool loopExists = detectLoopUsingFlyodInLL(head);
    cout << "Before loopExists?: " << loopExists << endl;

    cout << "Removing loop..." << endl;

    detectIntersectionAndRemoveLoop(head);

    loopExists = detectLoopUsingFlyodInLL(head);
    cout << "After loopExists?: " << loopExists << endl;
}