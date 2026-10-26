//* https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbar_codestudio_26thjan&leftPanelTabValue=SUBMISSION
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

/**
 * @brief Reverses a linked list in consecutive groups of k nodes.
 *
 * First verifies that the current group contains exactly k nodes.
 * If fewer than k nodes remain, the group is left unchanged.
 * Otherwise, reverses the current group iteratively and recursively
 * processes the remaining list, connecting the reversed groups together.
 *
 * @param head Pointer to the first node of the current linked list segment.
 * @param k Number of nodes to reverse in each group.
 * @return Pointer to the new head of the processed linked list.
 *
 * @note The final group remains unchanged if it contains fewer than k nodes.
 *
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(n/k) auxiliary recursion stack space.
 */
Node<int> *kReverse(Node<int> *head, int k)
{
    if (head == NULL)
        return NULL;

    //* Check whether the current group contains at least k nodes.
    bool groupIntact = true;
    Node<int> *groupIterator = head;
    for (int i = 1; i < k; i++)
    {
        if (groupIterator->next == NULL)
        {
            groupIntact = false;
            break;
        }
        groupIterator = groupIterator->next;
    }

    //* Preserve the remaining nodes in their original order when the group is incomplete.
    if (!groupIntact)
        return head;

    Node<int> *prev = NULL;
    Node<int> *curr = head;
    Node<int> *next = NULL;
    int count = 0;

    //* Reverse the links of the current group without changing the node values.
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //* The original head is now the group's tail; connect it to the recursively reversed remainder.
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }

    //* 'prev' points to the new head of the reversed group.
    return prev;
}

/**
 * @brief Prints a linked list in bracketed, comma-separated format.
 *
 * @param head Pointer to the first node of the linked list.
 *
 * @note Assumes head is not NULL.
 *
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(1).
 */
void printList(Node<int> *head)
{

    cout << "[";
    Node<int> *printPointer = head;

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

/**
 * @brief Creates a sample linked list, reverses it in groups of four, and prints both lists.
 *
 * @return Exit status of the program.
 *
 * Time Complexity: O(n), where n is the number of nodes.
 * Space Complexity: O(1), excluding the recursive stack used by kReverse.
 */
int main()
{
    Node<int> head = Node(1);
    Node<int> node1 = Node(2);
    head.next = &node1;
    Node<int> node2 = Node(3);
    node1.next = &node2;
    Node<int> node3 = Node(4);
    node2.next = &node3;
    Node<int> node4 = Node(5);
    node3.next = &node4;
    Node<int> node5 = Node(6);
    node4.next = &node5;
    Node<int> node6 = Node(7);
    node5.next = &node6;

    printList(&head);

    Node<int> *newHead = kReverse(&head, 4);
    printList(newHead);
}