
#include<iostream>
using namespace std;

//* Represents a human with a name and age.
class Human{
public:
    string name;
    int age;
};

/**
 * @brief Demonstrates how to create and use a pointer to a class object.
 *
 * The program dynamically allocates a Human object on the heap using the
 * `new` operator. It then shows the two equivalent ways of accessing an
 * object's members through a pointer:
 * 1. Dereference operator (`(*pointer).member`)
 * 2. Arrow operator (`pointer->member`)
 *
 * @return int Returns 0 after successful execution.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int main(){
    //* Create a Human object dynamically on the heap.
    Human *akshay = new Human;
    
    //* Access object members by first dereferencing the pointer.
    //? `(*akshay).member` accesses the object pointed to by `akshay`.
    (*akshay).name = "akshay";
    (*akshay).age = 24;
    
    
    // cout << (*akshay).name << endl;
    // cout << (*akshay).age << endl;
    
    //* The arrow operator (`->`) is shorthand for `(*pointer).member`.
    //? It provides a cleaner and more readable syntax for accessing members.
    cout << akshay->name << endl;
    cout << akshay->age << endl;
    
    //! Free the dynamically allocated memory to prevent a memory leak.
    delete akshay;
    
    return 0;
}
