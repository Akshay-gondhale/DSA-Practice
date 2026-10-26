#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    /**
     * @brief Creates a doubly linked list node.
     *
     * @param prev Pointer to the previous node.
     * @param data Value stored in the node.
     * @param next Pointer to the next node.
     */
    Node(Node *prev, int data, Node *next)
    {
        this->prev = prev;
        this->data = data;
        this->next = next;
    }
};

class DoublyLinkedList
{
public:
    int length = 0;
    Node *head = NULL;
    Node *tail = NULL;

    /**
     * @brief Creates a doubly linked list containing one node.
     *
     * The first node acts as both the head and tail because it is the only
     * node currently present in the list.
     *
     * @param num Value stored in the first node.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    DoublyLinkedList(int num)
    {
        //? The first node has no previous or next node.
        Node *headNode = new Node(NULL, num, NULL);
        head = headNode;
        tail = headNode;
        length = 1;
    };

    /**
     * @brief Adds a new node at the beginning of the list.
     *
     * @param num Value stored in the new node.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void addNodeAtHead(int num)
    {
        //? New node points forward to the current head.
        Node *newNode = new Node(NULL, num, this->head);

        //? The old head must point backward to the newly created node.
        this->head->prev = newNode;

        //? Make the new node the first node of the list.
        this->head = newNode;
        this->length++;
    }

    /**
     * @brief Adds a new node at the end of the list.
     *
     * @param num Value stored in the new node.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void addNodeAtTail(int num)
    {
        //? New node points backward to the current tail.
        Node *newNode = new Node(this->tail, num, NULL);

        //? Connect the old tail to the new node.
        this->tail->next = newNode;

        //? The new node becomes the last node.
        this->tail = newNode;
        this->length++;
    }

    /**
     * @brief Inserts a new node at the specified position.
     *
     * Traverses from the closer end of the doubly linked list to reduce
     * unnecessary traversal.
     *
     * @param num Value stored in the new node.
     * @param position Zero-based position where the node is inserted.
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

        //? Position 0 requires changing the head pointer.
        if (position == 0)
        {
            this->addNodeAtHead(num);
            return;
        }

        //? The last valid position is handled by the tail insertion logic.
        if (position == this->length - 1)
        {
            this->addNodeAtTail(num);
            return;
        }

        //? Use the middle as the boundary to decide which direction to traverse.
        int mid = this->length / 2;

        if (position <= mid)
        {
            int currentIndex = 0;
            Node *currentNode = this->head;

            //? Traverse from the head when the target is in the first half.
            while (currentIndex <= mid)
            {
                if (currentIndex == position)
                {
                    //? Insert the new node between prevNode and currentNode.
                    Node *newNode = new Node(currentNode->prev, num, currentNode);
                    Node *prevNode = currentNode->prev;

                    //? Connect the previous node forward to the new node.
                    prevNode->next = newNode;

                    //? Connect the current node backward to the new node.
                    currentNode->prev = newNode;

                    this->length++;
                    break;
                }
                currentNode = currentNode->next;
                currentIndex++;
            }
        }
        else
        {
            int currentIndex = this->length - 1;
            Node *currentNode = this->tail;

            //? Traverse backward from the tail when the target is in the second half.
            while (currentIndex > mid)
            {
                if (currentIndex == position)
                {
                    //? Insert the new node immediately before currentNode.
                    Node *newNode = new Node(currentNode->prev, num, currentNode);
                    Node *prevNode = currentNode->prev;

                    //? Connect the previous node forward to the new node.
                    prevNode->next = newNode;

                    //? Connect the current node backward to the new node.
                    currentNode->prev = newNode;

                    this->length++;
                    break;
                }
                currentNode = currentNode->prev;
                currentIndex--;
            }
        }
    }

    /**
     * @brief Removes the head node from the list.
     *
     * @note The implementation intentionally keeps at least one node in the list.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void popHead()
    {
        //? Prevent deleting the only node because the list must retain one element.
        if (this->length == 1)
        {
            cout << "Cannot delete the head. List must contain at least one element." << endl;
            return;
        }

        //? Save the second node before deleting the current head.
        Node *nextNodeAdd = this->head->next;

        //? Release the memory occupied by the old head.
        delete this->head;

        //? The new head has no node before it.
        nextNodeAdd->prev = NULL;

        //? Move the head pointer to the second node.
        this->head = nextNodeAdd;
        this->length--;
    }

    /**
     * @brief Removes the tail node from the list.
     *
     * @note The implementation intentionally keeps at least one node in the list.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void popTail()
    {
        //? Prevent deleting the only node because the list must retain one element.
        if (this->length == 1)
        {
            cout << "Cannot delete the tail. List must contain at least one element." << endl;
            return;
        }

        //? The node before the current tail will become the new tail.
        Node *newTail = this->tail->prev;

        //? The new tail must not point to any node after it.
        newTail->next = NULL;

        //? Release the memory occupied by the old tail.
        delete this->tail;

        //? Move the tail pointer to the previous node.
        this->tail = newTail;
        this->length--;
    }

    /**
     * @brief Deletes the node at the specified position.
     *
     * Traverses from the closer end of the doubly linked list and reconnects
     * the neighboring nodes after removing the target node.
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

        //? Deleting position 0 requires updating the head.
        if (position == 0)
        {
            this->popHead();
            return;
        }

        //? Deleting the last position requires updating the tail.
        if (position == this->length - 1)
        {
            this->popTail();
            return;
        }

        //? Choose the traversal direction based on the target's position.
        int mid = this->length / 2;

        if (position <= mid)
        {
            int currentIndex = 0;
            Node *currentNode = this->head;

            //? Search from the head when the target lies in the first half.
            while (currentIndex <= mid)
            {
                if (currentIndex == position)
                {
                    //? Save both neighbors before deleting the target node.
                    Node *nextNodeAddress = currentNode->next;
                    Node *prevNode = currentNode->prev;

                    //? Remove the target node from memory.
                    delete currentNode;

                    //? Skip the deleted node in the forward direction.
                    prevNode->next = nextNodeAddress;

                    //? Skip the deleted node in the backward direction.
                    nextNodeAddress->prev = prevNode;

                    this->length--;
                    break;
                }
                currentNode = currentNode->next;
                currentIndex++;
            }
        }
        else
        {
            int currentIndex = this->length - 1;
            Node *currentNode = this->tail;

            //? Search backward from the tail when the target lies in the second half.
            while (currentIndex > mid)
            {
                if (currentIndex == position)
                {
                    //? Save both neighbors before deleting the target node.
                    Node *nextNodeAddress = currentNode->next;
                    Node *prevNode = currentNode->prev;

                    //? Remove the target node from memory.
                    delete currentNode;

                    //? Skip the deleted node in the forward direction.
                    prevNode->next = nextNodeAddress;

                    //? Skip the deleted node in the backward direction.
                    nextNodeAddress->prev = prevNode;

                    this->length--;
                    break;
                }
                currentNode = currentNode->prev;
                currentIndex--;
            }
        }
    }

    /**
     * @brief Prints all elements of the list from head to tail.
     *
     * @note Traversal uses the next pointers starting from the head.
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

            //? Follow next pointers until every node has been visited.
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
    DoublyLinkedList *list = new DoublyLinkedList(5);
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
    DoublyLinkedList *list2 = new DoublyLinkedList(1);
    list2->addNodeAtTail(3);
    list2->addNodeAtTail(4);
    list2->addNodeAtTail(5);
    list2->addNodeAtTail(6);

    cout << "Before adding list:" << endl;
    list2->printList();

    cout << "After adding in list:" << endl;
    list2->insertNodeAtPosition(2, 3);
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
