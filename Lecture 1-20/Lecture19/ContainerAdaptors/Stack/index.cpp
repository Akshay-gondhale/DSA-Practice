// stack stores elements in reverse format like most recent element put in stack will be on top of stack
// example: dish set in wedding.
// format : last in first out
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<string> friends;
    friends.push("Rohit");
    friends.push("Praneet");
    friends.push("Akshay");

    cout << "Top element of friends: " << friends.top() << endl;
    cout << endl;

    // checking is stack empty
    cout << "Is stack empty? = " << friends.empty() << endl;
    cout << endl;
    // size of stack
    cout << "Size of stack: " << friends.size() << endl;
    cout << endl;

    // popping first element out of stack
    friends.pop();
    cout << "Top element of friends after popping: " << friends.top() << endl;
    cout << endl;
}