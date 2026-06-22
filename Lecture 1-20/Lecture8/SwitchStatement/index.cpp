// -----------------------------------------------------------------------------
// Learning focus: Switch Statement
// Purpose: Introduces the C++ fundamentals used in Switch Statement.
// Core idea: Read execution from top to bottom and observe how declarations, conditions, loops, and output statements change program flow.
// Complexity note: This is a language-feature demonstration; complexity is secondary to control flow.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// a simple calculator with switch statement

#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operator: ";
    cin >> op;
    switch (op)
    {
    case '+':
        cout << "Addition is: " << num1 + num2 << endl;
        break;
    case '-':
        cout << "Substraction is: " << num1 - num2 << endl;
        break;
    case '*':
        cout << "Multiplication is: " << num1 * num2 << endl;
        break;
    case '/':
        cout << "Division is: " << num1 / num2 << endl;
        break;

    default:
        cout << "Invalid Operation Passed." << endl;
        break;
    }
}