#include <bits/stdc++.h>
using namespace std;

class Car
{
    char *name;
    int mileage;
    int sittingCapacity;

public:
    //* Static members belong to the class itself rather than individual objects.
    //* Only one copy of a static variable exists, and it is shared by all objects.
    static int numOfWheels;

    /**
     * @brief Default constructor for the Car class.
     *
     * Allocates memory to store the car name. The actual name can be assigned later.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Car()
    {
        char *name = new char[100];
        this->name = name;
    }

    /**
     * @brief Parameterized constructor to initialize a Car object.
     *
     * Stores the provided values inside the object.
     *
     * @param name Pointer to the car name.
     * @param mileage Mileage of the car.
     * @param sittingCapacity Seating capacity of the car.
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
     * @brief Demonstrates how a static member function works.
     *
     * Static member functions belong to the class instead of any particular
     * object, so they can access only static members directly.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    static void tempStaticFunction()
    {
        cout << "Static function got called " << endl;

        //! Static functions do not have a 'this' pointer because they are not
        //! associated with any specific object.
        // cout << this->name << endl; // Error

        //* Static members can be accessed directly inside static functions.
        cout << numOfWheels << endl;
    }
};

//* Static data members must be defined outside the class.
//* This creates the single shared instance of the variable.
int Car::numOfWheels = 4;

int main()
{
    //* Static members can be accessed directly using the scope resolution operator (::)
    //* without creating any object.
    cout << Car::numOfWheels << endl;

    Car::tempStaticFunction();

    char *name = new char[100];
    strcpy(name, "nexon");

    Car nexon(name, 25, 5);

    //* Although static members can also be accessed through an object,
    //* accessing them using the class name is the recommended approach
    //* because they are shared across all objects.
    cout << nexon.numOfWheels << endl;
}