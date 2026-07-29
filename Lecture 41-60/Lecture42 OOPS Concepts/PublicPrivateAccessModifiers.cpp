#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Represents a human with both public and private data members.
 *
 * This class demonstrates the concept of access modifiers in C++. Public
 * members are accessible from outside the class, whereas private members
 * can only be accessed by the class's member functions.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
class Human
{
    //* By default, members of a class are private if no access specifier is provided.
    // string name;

public:
    //* Public data member that can be accessed directly from outside the class.
    string name;

private:
    //* Private data member that can only be accessed within the class.
    int age;
};

/**
 * @brief Demonstrates the use of public and private access modifiers.
 *
 * Creates an object of the Human class, assigns a value to its public
 * member, and prints it. Attempts to access the private member are
 * intentionally commented out because they result in compilation errors.
 *
 * @return int Returns 0 to indicate successful program execution.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int main()
{
    //* Create an object of the Human class.
    Human akshay;

    //* Valid because 'name' is a public data member.
    akshay.name = "Akshay";

    //* Invalid because 'age' is a private data member.
    // akshay.age = 25;

    //* Accessing a public member is allowed.
    cout << akshay.name << endl;

    //* Invalid because private members cannot be accessed directly.
    // cout << akshay.age << endl;
}