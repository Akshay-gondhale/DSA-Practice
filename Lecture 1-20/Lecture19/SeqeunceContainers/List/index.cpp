// list have two pointers one in front and one in last.
// you cannot do .at() in list.
#include <iostream>
#include <list>
using namespace std;

void printList(list<int> numArr)
{
    for (int i : numArr)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    // init list
    list<int> numList;
    numList.push_back(1);
    numList.push_back(2);
    numList.push_front(3);
    cout << "Init list: " << endl;
    printList(numList);
    cout << endl;

    // copying this in new list
    list<int> copyNumList(numList);
    cout << "Copy list: " << endl;
    printList(copyNumList);
    cout << endl;

    // size of list
    cout << "Size of list is: " << numList.size() << endl;
    cout << endl;

    // erase() method
    // this only deletes one element. you need to paas the pointer like numList.begin() and it will delete element
    // present at begin
    numList.erase(numList.begin());
    cout << "After erase method: ";
    printList(numList);
}