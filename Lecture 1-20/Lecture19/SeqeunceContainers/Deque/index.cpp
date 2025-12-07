// deques stands for doubly ended queue
// in this you can push elements from both the ends and also popup from both the ends
#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int> numArr)
{
    for (int i = 0; i < numArr.size(); i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // init
    deque<int> numDeque;
    // pushing elements from back
    numDeque.push_back(1);
    numDeque.push_back(2);
    // pushing elements from front
    numDeque.push_front(3);
    cout << "Init it deque: ";
    printDeque(numDeque);
    cout << endl;

    // to check if deque is empty
    cout << "Is Dequeu Empty? = " << numDeque.empty();
    cout << endl;

    // to check size of deqeu
    cout << "Size of deque is: " << numDeque.size() << endl;
    cout << endl;

    // popping element from front and back
    numDeque.pop_front();
    cout << "Post front elements popped: ";
    printDeque(numDeque);
    cout << endl;

    numDeque.pop_front();
    cout << "Post back elements popped: ";
    printDeque(numDeque);
    cout << endl;

    // getting element by intex
    cout << "Element on 0 index is: " << numDeque.at(0);
    cout << endl;

    // readding elements
    numDeque.push_front(1);
    numDeque.push_front(3);
    cout << "Post reading: ";
    printDeque(numDeque);
    cout << endl;

    // removing multiple elements from dequeu using erase function
    // here begin function will give index 0
    // so its removing from 0 -> 1
    numDeque.erase(numDeque.begin(), numDeque.begin() + 1);
    cout << "Post erase function: ";
    printDeque(numDeque);
}