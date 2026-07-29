#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Represents a hero with its associated attributes.
 *
 * This class currently contains a single private data member to demonstrate
 * how object size is determined in C++.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
class Hero
{
    //* Private data member representing the hero's health.
    int health;
};

/**
 * @brief An empty class used to demonstrate the size of an empty object.
 *
 * According to the C++ standard, an empty class still occupies at least
 * one byte of memory so that each object has a unique memory address.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
class EmptyClass
{
};

/**
 * @brief Demonstrates the memory size occupied by class objects.
 *
 * Creates objects of a non-empty class and an empty class, then prints
 * their sizes using the sizeof operator.
 *
 * @return int Returns 0 to indicate successful program execution.
 *
 * @note The size of an empty class is typically 1 byte because C++ requires
 *       every object to have a unique address, even if it contains no data members.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int main()
{
    //* Create an object of the Hero class.
    Hero ramesh;

    //* Prints 4 because the Hero class contains a single integer data member.
    //* On most systems, an int occupies 4 bytes.
    cout << "Size of ramesh object: " << sizeof(ramesh) << endl;

    //* Create an object of the EmptyClass.
    EmptyClass emptyClass;

    //* Prints 1 because C++ allocates at least one byte for every empty object
    //* to ensure that each object has a unique memory address.
    cout << "Size of emptyClass object: " << sizeof(emptyClass) << endl;

    return 0;
}