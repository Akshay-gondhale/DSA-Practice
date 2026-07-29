#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Represents a human with encapsulated data members.
 *
 * This class demonstrates the concept of encapsulation in C++ by keeping
 * data members private and providing public getter and setter functions
 * to access and modify them in a controlled manner.
 *
 * Time Complexity: O(1) for all member functions
 * Space Complexity: O(1)
 */
class Human
{
    //* Private data members can only be accessed through member functions.
    string name;
    int age;

public:
    /**
     * @brief Returns the name of the human.
     *
     * @return string The stored name.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    string getName()
    {
        return name;
    }

    /**
     * @brief Returns the age of the human.
     *
     * @return int The stored age.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    int getAge()
    {
        return age;
    }

    /**
     * @brief Updates the name of the human.
     *
     * @param humanName The new name to be assigned.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void setName(string humanName)
    {
        name = humanName;
    }

    /**
     * @brief Updates the age of the human after validation.
     *
     * Demonstrates one of the advantages of setters—they can validate
     * input before updating private data members.
     *
     * @param humanAge The new age to be assigned.
     *
     * @note The validation logic in this example contains a mistake.
     *       It checks the existing member variable `age` instead of the
     *       input parameter `humanAge`. For proper validation, the
     *       condition should compare `humanAge` with the allowed limit.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void setAge(int humanAge)
    {
        //* Validate the age before updating it.
        if (age > 120)
        {
            cout << "Age cannot be more than 120" << endl;
            return;
        }

        //* Store the validated age.
        age = humanAge;
    }
};

/**
 * @brief Demonstrates the use of getters and setters.
 *
 * Creates a Human object, initializes its private data members through
 * setter functions, and retrieves them using getter functions.
 *
 * @return int Returns 0 to indicate successful program execution.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int main()
{
    //* Create a Human object.
    Human akshay;

    //* Modify private data members through public setter functions.
    akshay.setName("Akshay");
    akshay.setAge(24);

    //* Access private data members through public getter functions.
    cout << "Name of human object: " << akshay.getName() << endl;
    cout << "Age of human object: " << akshay.getAge() << endl;
}