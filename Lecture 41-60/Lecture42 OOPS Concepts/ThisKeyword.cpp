#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Represents a car with basic attributes.
 *
 * This example demonstrates the usage of the `this` pointer in C++.
 * The `this` pointer refers to the memory address of the object that
 * invoked the member function, making it useful for accessing members
 * of the current object.
 */
class Car
{
    int mileage;
    int seatingCapacity;

public:
    /**
     * @brief Prints the memory address of the current object.
     *
     * The `this` pointer stores the address of the object on which
     * the member function is invoked.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void printAddress()
    {
        //* `this` is a pointer that points to the current object.
        cout << this << endl;
    }

    /**
     * @brief Sets the mileage of the current car object.
     *
     * @param mileage Mileage value to assign.
     *
     * @note `this->mileage` explicitly refers to the member variable,
     * while `mileage` refers to the function parameter. Using `this`
     * resolves the naming conflict.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void setMileage(int mileage)
    {
        //* Use the `this` pointer to access the member variable when a local parameter has the same name.
        this->mileage = mileage;
    }

    /**
     * @brief Returns the mileage of the current car object.
     *
     * @return int The stored mileage.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    int getMileage()
    {
        //* Access the member variable of the current object using the `this` pointer.
        return this->mileage;
    }
};

/**
 * @brief Demonstrates the usage of the `this` pointer.
 *
 * Creates a `Car` object, compares its address with the value stored
 * in the `this` pointer, and uses member functions to modify and
 * retrieve object data.
 *
 * @return int Returns the program exit status.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int main()
{
    Car nexon;

    //* Both statements print the same address because `this` stores the address of the object invoking the member function.
    cout << &nexon << endl;
    nexon.printAddress();

    //* Update and retrieve the mileage using member functions.
    nexon.setMileage(25);
    cout << nexon.getMileage() << endl;
}