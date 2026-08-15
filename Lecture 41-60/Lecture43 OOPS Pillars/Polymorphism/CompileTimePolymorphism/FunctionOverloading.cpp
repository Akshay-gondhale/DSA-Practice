#include <bits/stdc++.h>
using namespace std;

//*  Function overloading is a compile-time polymorphism technique where
//*  multiple functions have the same name but different parameter lists.
//?  The compiler determines which overloaded function to call based on
//?  the number and type of arguments passed.
class MyMath
{
public:
    /**
     * @brief Adds two numbers and displays their sum.
     *
     * This is one of multiple overloaded versions of add(). The compiler
     * selects this version when two integer arguments are provided.
     *
     * @param num1 First number.
     * @param num2 Second number.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void add(int num1, int num2)
    {

        cout << "Two num sum is: " << num1 + num2 << endl;
    }

    /**
     * @brief Adds three numbers and displays their sum.
     *
     * This overloaded version is selected by the compiler when three
     * integer arguments are provided.
     *
     * @param num1 First number.
     * @param num2 Second number.
     * @param num3 Third number.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void add(int num1, int num2, int num3)
    {
        cout << "Three num sum is: " << num1 + num2 + num3 << endl;
    }

    /**
     * @brief Adds four numbers and displays their sum.
     *
     * This overloaded version is selected by the compiler when four
     * integer arguments are provided.
     *
     * @param num1 First number.
     * @param num2 Second number.
     * @param num3 Third number.
     * @param num4 Fourth number.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void add(int num1, int num2, int num3, int num4)
    {
        cout << "Four num sum is: " << num1 + num2 + num3 + num4 << endl;
    }
};

int main()
{
    MyMath mathObj;

    //? The compiler identifies the appropriate overloaded add() function
    //? based on the number of arguments passed.
    mathObj.add(2, 3);
    mathObj.add(4, 5, 6);
    mathObj.add(7, 8, 9, 10);
}