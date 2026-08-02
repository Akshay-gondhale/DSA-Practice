#include <bits/stdc++.h>
using namespace std;

//* Represents a Car class to demonstrate the difference between
//* shallow copy and deep copy when working with dynamically allocated memory.
class Car
{

public:
    int mileage;
    int sittingCapacity;
    char *name;

    /**
     * @brief Default constructor.
     *
     * Allocates memory on the heap for storing the car name.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Car()
    {
        this->name = new char[100];
        cout << "Default constructor got called" << endl;
    }

    /**
     * @brief Parameterized constructor.
     *
     * Initializes all data members.
     *
     * @param name Pointer to the car name.
     * @param mileage Mileage of the car.
     * @param sittingCapacity Seating capacity of the car.
     *
     * @note This constructor directly stores the pointer instead of creating
     * a copy of the string.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Car(char *name, int mileage, int sittingCapacity)
    {
        this->name = name;
        this->mileage = mileage;
        this->sittingCapacity = sittingCapacity;
    }

    /**
     * @brief Copy constructor.
     *
     * Creates a new object by copying another Car object.
     *
     * @param carToCopy Object to copy.
     *
     * @note The parameter must be passed by reference. Passing it by value
     * would invoke the copy constructor again while creating the parameter
     * itself. This process repeats indefinitely, leading to infinite recursive
     * copy constructor calls and eventually a stack overflow.
     *
     * Time Complexity: O(N), where N is the length of the name.
     * Space Complexity: O(N)
     */
    Car(Car &carToCopy)
    {
        // ------------------------------------------------------------------
        // SHALLOW COPY (Compiler Generated Behaviour)
        // ------------------------------------------------------------------
        //
        // A shallow copy simply copies the pointer:
        //
        //      this->name = carToCopy.name;
        //
        // If our copy constructor looked like this:
        //
        //      Car(Car &carToCopy)
        //      {
        //          this->name = carToCopy.name;   // Pointer is copied, not data
        //          this->mileage = carToCopy.mileage;
        //          this->sittingCapacity = carToCopy.sittingCapacity;
        //      }
        //
        // Memory Layout:
        //
        //                Heap
        //          +--------------+
        //          |   "nexon"    |
        //          +--------------+
        //             ^        ^
        //             |        |
        //      nexon.name   punch.name
        //
        // Both objects point to the SAME heap memory.
        //
        // Therefore:
        //
        //      punch.name[0] = 'P';
        //
        // changes the shared memory itself, so the output becomes:
        //
        //      nexon -> "Pexon"
        //      punch -> "Pexon"
        //
        // Another problem appears if a destructor deletes 'name'.
        //
        // 1. First object deletes the shared memory.
        // 2. Second object still holds the same pointer
        //    (Dangling Pointer).
        // 3. Second destructor deletes the same memory again,
        //    causing Double Deletion (Undefined Behaviour).
        //
        // ------------------------------------------------------------------
        // DEEP COPY (Implemented Below)
        // ------------------------------------------------------------------
        //
        // Instead of copying only the pointer, allocate a NEW memory block
        // for the copied object and copy the actual string into it.
        //
        // Before Deep Copy:
        //
        //      nexon.name ----+
        //                     |
        //                     +----> Heap Block #1 -> "nexon"
        //                     |
        //      punch.name ----+
        //
        // Both objects share the same memory.
        //
        // After Deep Copy:
        //
        //      nexon.name ----> Heap Block #1 -> "nexon"
        //
        //      punch.name ----> Heap Block #2 -> "nexon"
        //
        // Now each object owns its own independent memory.
        //
        // Therefore:
        //
        //      punch.name[0] = 'P';
        //
        // modifies only punch's string.
        //
        // Result:
        //
        //      nexon -> "nexon"
        //      punch -> "Pexon"
        //
        // Since each object owns a separate heap allocation, both objects
        // can safely free their own memory without affecting each other.

        //* Allocate a new heap memory for the copied object's name.
        char *name = new char[100];

        //* Copy the string from the source object's memory into the new memory.
        strcpy(name, carToCopy.name);

        //* Store the newly created pointer in this object.
        this->name = name;

        //* Copy the remaining primitive data members.
        this->mileage = carToCopy.mileage;
        this->sittingCapacity = carToCopy.sittingCapacity;
    }

    /**
     * @brief Prints the details of the car.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void print()
    {
        cout << "[name: " << this->name
             << ", mileage: " << this->mileage
             << ", sittingCapacity: " << this->sittingCapacity << "]" << endl;
    }
};

int main()
{
    //* Allocate memory on the heap to store the original car name.
    char *name = new char[100];
    strcpy(name, "nexon");

    //* Create the original Car object using the parameterized constructor.
    Car nexon(name, 25, 5);

    cout << "Original Object:" << endl;
    nexon.print();

    //* Create another object by copying 'nexon'.
    //* This invokes the custom copy constructor.
    Car punch(nexon);

    cout << "\nCopied Object:" << endl;
    punch.print();

    //* At this point:
    //*
    //* nexon.name ----------------------+
    //*                                  |
    //*                                  v
    //*                          Heap Block #1
    //*                          +-----------+
    //*                          | "nexon"   |
    //*                          +-----------+
    //*
    //* punch.name -----------------------+
    //*                                   |
    //*                                   v
    //*                           Heap Block #2
    //*                           +-----------+
    //*                           | "nexon"   |
    //*                           +-----------+
    //*
    //* Since a deep copy was performed, both objects own different
    //* memory locations even though their contents are identical.

    //* Modify only the copied object's name.
    punch.name[0] = 'P';

    //* After modification:
    //*
    //* nexon.name ----------------------+
    //*                                  |
    //*                                  v
    //*                          Heap Block #1
    //*                          +-----------+
    //*                          | "nexon"   |
    //*                          +-----------+
    //*
    //* punch.name -----------------------+
    //*                                   |
    //*                                   v
    //*                           Heap Block #2
    //*                           +-----------+
    //*                           | "Pexon"  |
    //*                           +-----------+
    //*
    //* Only punch's name changes because both objects now have
    //* independent copies of the string.
    //*
    //* If this had been a shallow copy:
    //*
    //*      nexon.name ----+
    //*                     |
    //*                     +----> Heap Block -> "Pexon"
    //*                     |
    //*      punch.name ----+
    //*
    //* Both objects would have printed "Pexon" because they would
    //* be sharing the same heap memory.

    cout << "\nAfter modifying copied object:" << endl;

    cout << "Original Object:" << endl;
    nexon.print();

    cout << "Copied Object:" << endl;
    punch.print();

    return 0;
}