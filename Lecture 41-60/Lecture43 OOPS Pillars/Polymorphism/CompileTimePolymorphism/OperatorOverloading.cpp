#include <bits/stdc++.h>
using namespace std;

//*  Operator overloading is a compile-time polymorphism technique that
//*  allows operators to work with user-defined objects.
//?  Here, the + operator is overloaded to add the values stored in
//?  two NumContainer objects.
class NumContainer
{
    int num;

public:
    /**
     * @brief Initializes a NumContainer object with a given number.
     *
     * @param num Number to be stored in the object.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    NumContainer(int num)
    {
        this->num = num;
    }

    /**
     * @brief Overloads the + operator to add two NumContainer objects.
     *
     * When the expression `num1 + num2` is encountered, the compiler
     * internally invokes this operator function on num1 with num2 as
     * the argument.
     *
     * @param obj2 Second NumContainer object to be added.
     * @return Sum of the numbers stored in the two objects.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    int operator+(NumContainer &obj2)
    {
        return this->num + obj2.num;
    }
};

int main()
{
    NumContainer num1(5);
    NumContainer num2(8);

    //? The overloaded + operator is called to add the values of num1 and num2.
    int result = num1 + num2;

    cout << "result is: " << result << endl;
}