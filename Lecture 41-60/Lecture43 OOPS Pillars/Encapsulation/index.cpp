#include <bits/stdc++.h>
using namespace std;
//! Encapsulation means bundling data and the functions that operate on that
//! data inside a single class, while controlling access to the data using
//! access specifiers such as private, protected, and public.
//
//? Here, Human encapsulates its data members and provides controlled access
//? based on their access level. This prevents external code from directly
//? accessing restricted data such as country and age.

class Human
{
protected:
    int age;

private:
    string country;

public:
    string name;

    /**
     * @brief Creates a Human object and initializes its data.
     *
     * The class demonstrates encapsulation by keeping different data members
     * under different access levels. Private and protected members cannot be
     * accessed directly from outside the class.
     *
     * @param name Name of the human.
     * @param country Country of the human.
     * @param age Age of the human.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Human(string &name, string &country, int age)
    {
        this->name = name;
        this->country = country;
        this->age = age;
    }

    /**
     * @brief Prints all the data of the human.
     *
     * The function can access private and protected members because it is
     * a member function of the Human class.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void printData()
    {
        cout << "[name: " << this->name << ", country: " << this->country << ", age: " << this->age << "]" << endl;
    }
};

/**
 * @brief Demonstrates encapsulation and access control in C++.
 *
 * The Human class contains public, protected, and private data members.
 * Members with restricted access cannot be directly accessed from main().
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int main()
{
    string name = "akshay";
    string country = "India";
    Human akshay(name, country, 24);

    //? Protected members cannot be accessed directly from outside the class.
    // akshay.age = 40; // ERROR

    //? Public members can be accessed directly from outside the class.
    akshay.name = "Rahul";

    //? Private members cannot be accessed directly from outside the class.
    // akshay.country = "USA"; // ERROR

    akshay.printData();
}