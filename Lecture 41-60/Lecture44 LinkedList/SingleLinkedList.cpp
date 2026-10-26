#include <bits/stdc++.h>
using namespace std;

//* Represents a single node in the singly linked list.
class Node
{
public:
    int data;
    Node *next;

    /**
     * @brief Creates a new linked-list node.
     *
     * Stores the given value and initializes the next pointer.
     *
     * @param data Value to store in the node.
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

//* Manages a singly linked list while maintaining pointers to both head and tail.
class SingleLinkedList
{
public:
    int length = 0;
    Node *head = NULL;
    Node *tail = NULL;

    /**
     * @brief Creates a linked list containing the first node.
     *
     * The newly created node becomes both the head and tail because
     * the list initially contains only one node.
     *
     * @param num Value to store in the first node.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    SingleLinkedList(int num)
    {
        //? Create the first node and make it both the head and tail.
        Node *headNode = new Node(num, NULL);
        head = headNode;
        tail = headNode;
        length = 1;
    };

    /**
     * @brief Adds a new node at the beginning of the linked list.
     *
     * The new node points to the current head, and then becomes the new head.
     *
     * @param num Value to store in the new node.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void addNodeAtHead(int num)
    {
        Node *newNode = new Node(num, this->head);
        this->head = newNode;
        this->length++;
    }

    /**
     * @brief Adds a new node at the end of the linked list.
     *
     * Since the list maintains a tail pointer, the new node can be
     * attached directly without traversing the list.
     *
     * @param num Value to store in the new node.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void addNodeAtTail(int num)
    {
        Node *newNode = new Node(num, NULL);
        this->tail->next = newNode;
        this->tail = newNode;
        this->length++;
    }

    /**
     * @brief Inserts a new node at the specified position.
     *
     * Traverses the list until the requested position is reached and
     * connects the new node between the previous and current nodes.
     *
     * @param num Value to store in the new node.
     * @param position Zero-based position at which the node is inserted.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void insertNodeAtPosition(int num, int position)
    {
        if (position >= this->length)
        {
            cout << "Position cannot be more than total length of linked list" << endl;
            return;
        }
        if (position == 0)
        {
            this->addNodeAtHead(num);
            return;
        }
        if (position == this->length - 1)
        {
            this->addNodeAtTail(num);
            return;
        }
        int currentIndex = 0;
        Node *currentNode = this->head;
        Node *prevNode = this->head;
        while (currentIndex < this->length)
        {
            if (currentIndex == position)
            {
                //? Insert the new node between the previous node and current node.
                Node *newNode = new Node(num, currentNode);
                prevNode->next = newNode;
                this->length++;
                break;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
            currentIndex++;
        }
    }

    /**
     * @brief Removes the first node from the linked list.
     *
     * The head is moved to the second node before the old head is deleted.
     *
     * @note Assumes the linked list contains at least one node.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void popHead()
    {
        Node *nextNodeAdd = this->head->next;
        delete this->head;
        this->head = nextNodeAdd;
        this->length--;
    }

    /**
     * @brief Removes the last node from the linked list.
     *
     * A singly linked list cannot move backward from the tail, so the
     * list must be traversed to find the second-last node.
     *
     * @note Assumes the linked list contains at least two nodes.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void popTail()
    {
        Node *currentNode = this->head;
        int currentIndex = 0;

        //? Find the second-last node because it must become the new tail.
        while (currentIndex < this->length - 2)
        {
            currentNode = currentNode->next;
            currentIndex++;
        }
        currentNode->next = NULL;
        delete this->tail;
        this->tail = currentNode;
        this->length--;
    }

    /**
     * @brief Deletes the node at the specified position.
     *
     * Traverses the list to locate the target node, then reconnects the
     * previous node directly to the target's next node.
     *
     * @param position Zero-based position of the node to delete.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void deleteNodeAtPosition(int position)
    {
        if (position >= this->length)
        {
            cout << "Position cannot be more than total length of linked list" << endl;
            return;
        }
        if (position == 0)
        {
            this->popHead();
            return;
        }
        if (position == this->length - 1)
        {
            this->popTail();
            return;
        }
        int currentIndex = 0;
        Node *currentNode = this->head;
        Node *prevNode = this->head;
        while (currentIndex < this->length)
        {
            if (currentIndex == position)
            {
                //? Save the next node before deleting the current node.
                Node *nextNodeAddress = currentNode->next;
                delete currentNode;
                prevNode->next = nextNodeAddress;
                this->length--;
                break;
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
            currentIndex++;
        }
    }

    /**
     * @brief Prints all elements of the linked list in array-like format.
     *
     * Traverses the list from head to tail and prints each node's data.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    void printList()
    {
        if (this->length > 0)
        {
            cout << "[";
            Node *printPointer = this->head;
            int printPointerIndex = 0;
            while (printPointerIndex < this->length)
            {
                cout << printPointer->data;
                if (printPointer->next != NULL)
                {
                    cout << ", ";
                }
                printPointer = printPointer->next;
                printPointerIndex++;
            }
            cout << "]" << endl;
        }
    }
};

int main()
{
    SingleLinkedList *list = new SingleLinkedList(5);
    list->printList();
    cout << "Adding node in tail" << endl;
    list->addNodeAtTail(6);
    list->printList();
    cout << "Adding node in head" << endl;
    list->addNodeAtHead(4);
    list->printList();
    delete list;

    cout << endl
         << endl
         << "Creating new list for adding elements in middle:" << endl;
    SingleLinkedList *list2 = new SingleLinkedList(1);
    list2->addNodeAtTail(3);
    list2->addNodeAtTail(4);
    list2->addNodeAtTail(5);
    list2->addNodeAtTail(6);

    cout << "Before adding list:" << endl;
    list2->printList();

    cout << "After adding in list:" << endl;
    list2->insertNodeAtPosition(2, 1);
    list2->printList();

    cout << "After deleting 2nd element:" << endl;
    list2->deleteNodeAtPosition(1);
    list2->printList();

    cout << "After deleting head element:" << endl;
    list2->popHead();
    list2->printList();

    cout << "After deleting tail element:" << endl;
    list2->popTail();
    list2->printList();
    delete list2;
}