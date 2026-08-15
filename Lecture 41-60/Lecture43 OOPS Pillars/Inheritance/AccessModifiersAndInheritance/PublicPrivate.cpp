#include <bits/stdc++.h>
using namespace std;

//*  Demonstrates how the access modifier used during inheritance
//*  controls the accessibility of the base class members through
//*  the derived class object.

class Human
{
public:
    int age;

    /**
     * @brief Prints a message representing a speaking action.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void speaking()
    {
        cout << "Speaking" << endl;
    }
};

/*
 *? Access Modifier Effect During Inheritance
 *
 *  Base Class Member     | public      | protected   | private
 *  ------------------------------------------------------------
 *  public member         | public      | protected   | private
 *  protected member      | protected   | protected   | private
 *  private member        | inaccessible| inaccessible| inaccessible
 *
 *? Note:
 *  - Base class private members are never directly accessible
 *    inside the derived class.
 *  - The inheritance modifier changes the accessibility of
 *    public and protected members in the derived class.
 */
class Male : private Human
{
public:
    /**
     * @brief Prints a greeting message.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void greet()
    {
        cout << "Hello programmer" << endl;
    }
};

int main()
{
    Male akshay;

    //? age is public in Human, but becomes private in Male
    //? because Human is inherited using private inheritance.
    // akshay.age = 24; // Error because Human is inherited as private

    //? speaking() is public in Human, but becomes private in Male
    //? because Human is inherited using private inheritance.
    // akshay.speaking();      // Error because Human is inherited as private

    //? greet() is directly declared as public inside Male,
    //? so it can be accessed using a Male object.
    akshay.greet();
}