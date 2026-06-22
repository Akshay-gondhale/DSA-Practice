// -----------------------------------------------------------------------------
// Learning focus: Fibonacci Series
// Purpose: Generates or calculates Fibonacci Series.
// Core idea: Each term is formed from the two preceding terms; recursive versions directly mirror this recurrence.
// Complexity note: The iterative version is O(n); naive recursion is exponential and uses O(n) stack depth.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num <= 2)
    {
        cout << "Please enter a number greater than 2" << endl;
        return 0;
    }
    int a = 0;
    int b = 1;
    cout << a << " " << b << " ";
    for (int i = 2; i < num; i++)
    {
        int nextNumber = a + b;
        cout << nextNumber << " ";
        a = b;
        b = nextNumber;
    }
}