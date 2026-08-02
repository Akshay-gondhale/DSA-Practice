#include <bits/stdc++.h>
using namespace std;
//* Demonstrates the copy assignment operator.
class Car
{
    //! Pointer used to store the address of the car name.
    //! The actual character array is allocated dynamically on the heap.
    char *name;

    int mileage;
    int sittingCapacity;

public:
    /**
     * @brief Default constructor.
     *
     * Allocates memory for the car name so the object has its own
     * character buffer. The name itself is not initialized here.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Car()
    {
        //* Allocate memory for storing the name.
        char *name = new char[100];
        this->name = name;
    }

    /**
     * @brief Parameterized constructor.
     *
     * Initializes all data members using the provided values.
     *
     * @note This constructor performs a shallow copy of the name pointer.
     * Both the external pointer and the object point to the same character array.
     *
     * @param name Pointer to the character array containing the car name.
     * @param mileage Mileage of the car.
     * @param sittingCapacity Seating capacity of the car.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Car(char *name, int mileage, int sittingCapacity)
    {
        //* Store the pointer directly (shallow copy).
        this->name = name;
        this->mileage = mileage;
        this->sittingCapacity = sittingCapacity;
    }

    /**
     * @brief Prints all details of the car.
     *
     * Displays the stored name, mileage, and seating capacity.
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
    //* Dynamically allocate memory for the first car name.
    char *name = new char[100];

    //* Copy the string into the allocated character array.
    strcpy(name, "nexon");

    //* Creates a Car object using the provided pointer.
    Car nexon(name, 25, 5);
    nexon.print();

    //* Dynamically allocate memory for the second car name.
    char *punchName = new char[100];
    strcpy(punchName, "punch");

    Car punch(punchName, 25, 5);
    punch.print();

    //* Default assignment operator performs a member-wise copy.
    //* Since 'name' is a pointer, only its address is copied.
    //* After this assignment, both objects point to the same name buffer ("nexon").
    //* The original memory holding "punch" becomes inaccessible, resulting in a memory leak.
    punch = nexon;

    //* Both objects now print the same data because they share the same pointer.
    punch.print();
}