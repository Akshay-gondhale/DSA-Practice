#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Represents a human with basic properties.
 *
 * This example demonstrates constructor overloading in C++. The class
 * contains both a default constructor and a parameterized constructor
 * to illustrate how object initialization works.
 */
class Human

{

public:
    int age;

    //* The compiler automatically provides a default constructor if no constructor is explicitly defined.
    //* A constructor is a special member function that is invoked automatically whenever an object is created.
    //* To define custom initialization behavior, declare a constructor with the same name as the class.
    //* Constructors do not have a return type.
    //* Constructors must be accessible (typically public) to allow object creation outside the class.

    /**
     * @brief Constructs a Human object using the default constructor.
     *
     * Initializes the object without requiring any arguments.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Human()

    {

        cout << "Constructor got called" << endl;
    }

    //* Parameterized constructor.
    //* Use this constructor when object creation requires initial data.
    //* Since a user-defined constructor exists, the compiler no longer generates the implicit default constructor.
    //* If both parameterized and default construction should be supported, define both constructors explicitly.

    /**
     * @brief Constructs a Human object with the specified age.
     *
     * Initializes the object's age during creation.
     *
     * @param humanAge Age to assign to the object.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    Human(int humanAge)

    {

        age = humanAge;

        cout << "Parameterised constructor got called" << endl;
    }
};

/**
 * @brief Demonstrates object creation using different constructors.
 *
 * Creates one object using the default constructor and another using
 * the parameterized constructor to illustrate constructor overloading.
 *
 * @return int Returns the program exit status.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int main()

{

    //* Creating an object without arguments invokes the default constructor.
    Human akshay;

    //* Creating an object with an argument invokes the matching parameterized constructor.
    Human ramesh(15);
}