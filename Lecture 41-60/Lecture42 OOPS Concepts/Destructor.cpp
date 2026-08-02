#include <bits/stdc++.h>
using namespace std;

class Car
{
    char *name;
    int mileage;
    int sittingCapacity;

public:
    // Default constructor
    Car() {};

    // Parameterized constructor
    Car(char *name, int mileage, int sittingCapacity)
    {
        this->name = name;
        this->mileage = mileage;
        this->sittingCapacity = sittingCapacity;
    }

    // Destructor
    // This gets called automatically whenever an object is destroyed.
    // It is generally used to release dynamically allocated resources
    // owned by the object and perform any necessary cleanup.
    //
    // A destructor is declared using the class name prefixed with '~'.
    ~Car()
    {
        cout << "Destructor got called" << endl;

        // Free the dynamically allocated memory owned by this object.
        delete name;
    }
};

int main()
{
    // Allocate memory for the car name on the heap.
    char *name = new char[100];
    strcpy(name, "nexon");

    // Object created on the stack.
    // Its destructor will be called automatically when main() ends.
    Car nexon(name, 25, 5);

    char *name2 = new char[100];
    strcpy(name2, "punch");

    // Object created on the heap.
    Car *punch = new Car(name2, 25, 5);

    // Heap-allocated objects must be deleted manually.
    // Otherwise, their destructor will never be called, causing
    // resource leaks (such as memory leaks).
    delete punch;
}