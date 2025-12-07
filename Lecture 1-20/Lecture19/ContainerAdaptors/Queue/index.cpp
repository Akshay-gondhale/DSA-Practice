// queue stores data in same sequence as they are entered. In this first element entered will go out first
// example: any queue like queue for movie tickets
// format : first in first out
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    // init
    queue<string> bhandara;
    bhandara.push("Akshay");
    bhandara.push("Praneet");
    bhandara.push("Rohit");

    // prinint first element
    cout << "First element is: " << bhandara.front() << endl;
    cout << endl;

    // prinint last element
    cout << "Last element is: " << bhandara.back() << endl;
    cout << endl;

    // size of queue
    cout << "Size of queue is: " << bhandara.size() << endl;
    cout << endl;

    // popping element
    bhandara.pop();
    cout << "Size after pop: " << bhandara.size() << endl;
    cout << "First element after popping is: " << bhandara.front() << endl;
    cout << "Last element after popping is: " << bhandara.back() << endl;
    cout << endl;
}