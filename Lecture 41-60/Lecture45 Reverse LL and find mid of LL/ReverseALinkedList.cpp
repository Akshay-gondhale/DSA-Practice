// https://www.naukri.com/code360/problems/reverse-the-singly-linked-list_799897?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// with basic for loop
/**
 * @brief Reverses a singly linked list iteratively.
 *
 * Reverses each node's next pointer in-place using three pointers:
 * previous, current, and next. The original tail becomes the new head.
 *
 * @param head Pointer to the head node of the linked list.
 * @return Pointer to the new head of the reversed linked list.
 *
 * @note Returns NULL when the input list is empty.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
// {
//     //! An empty list has nothing to reverse.
//     if (head == NULL)
//         return NULL; // edge case

//     //* prevNode represents the portion of the list that has already been reversed.
//     LinkedListNode<int> *prevNode = NULL;
//     //* currentNode traverses the original list and reverses its links.
//     LinkedListNode<int> *currentNode = head;
//     while (currentNode->next != NULL)
//     {
//         //* Save the next node before changing the current node's link.
//         LinkedListNode<int> *nextNode = currentNode->next;

//         //? Point the current node backward to the already reversed portion.
//         currentNode->next = prevNode;
//         prevNode = currentNode;
//         currentNode = nextNode;
//     }

//     //? Reverse the final link so the original tail becomes the new head.
//     currentNode->next = prevNode; // for tail
//     return currentNode;
// }

//? Recursive approach to reverse the linked list.
/**
 * @brief Recursively reverses a singly linked list.
 *
 * Recursively reverses the list starting from the second node, then places
 * the current head after the reversed portion by changing the next pointers.
 *
 * @param head Pointer to the current head node of the linked list.
 * @return Pointer to the new head of the reversed linked list.
 *
 * @note The recursion reaches the original tail, which becomes the new head.
 *
 * Example:
 * Input:  1 -> 2 -> 3 -> 4 -> NULL
 *
 * Execution:
 * reverseLL(1)
 *   -> reverseLL(2)
 *      -> reverseLL(3)
 *         -> reverseLL(4)
 *
 * At node 4:
 *   4 -> NULL
 *
 * Returning to node 3:
 *   4 -> 3 -> NULL
 *
 * Returning to node 2:
 *   4 -> 3 -> 2 -> NULL
 *
 * Returning to node 1:
 *   4 -> 3 -> 2 -> 1 -> NULL
 *
 * Output: 4 -> 3 -> 2 -> 1 -> NULL
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to the recursive call stack.
 */
LinkedListNode<int> *reverseLL(LinkedListNode<int> *head)
{
    //? An empty list or a single-node list is already reversed.
    if (head == NULL || head->next == NULL)
        return head;

    //* Recursively reverse the list starting from the next node.
    LinkedListNode<int> *smallHeadPointer = reverseLL(head->next);

    //? Attach the current node after its next node, reversing their link.
    head->next->next = head;

    //! Break the original forward link to avoid creating a cycle.
    head->next = NULL;

    return smallHeadPointer;
}

/**
 * @brief Reverses a singly linked list using recursion.
 *
 * Delegates the actual recursive reversal to reverseLL().
 *
 * @param head Pointer to the head node of the linked list.
 * @return Pointer to the new head of the reversed linked list.
 *
 * Example:
 * Input:  1 -> 2 -> 3 -> 4 -> NULL
 * Output: 4 -> 3 -> 2 -> 1 -> NULL
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to the recursive call stack.
 */
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    return reverseLL(head);
}
void printList(LinkedListNode<int> *head)
{

    cout << "[";
    LinkedListNode<int> *printPointer = head;

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
    LinkedListNode<int> head = LinkedListNode(1);
    LinkedListNode<int> node1 = LinkedListNode(2);
    head.next = &node1;
    LinkedListNode<int> node2 = LinkedListNode(3);
    node1.next = &node2;

    printList(&head);

    LinkedListNode<int> *newHead = reverseLinkedList(&head);
    printList(newHead);
}