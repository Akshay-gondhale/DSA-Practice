// -----------------------------------------------------------------------------
// Learning focus: Pattern13
// Purpose: Prints the Pattern13 console pattern using nested loops.
// Core idea: The outer loop selects a row; inner loops calculate that row's spaces, symbols, letters, or numbers.
// Complexity note: For an n-by-n style pattern, time is O(n^2); only loop counters use extra space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
//   *
//  **
// ***

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < i + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}