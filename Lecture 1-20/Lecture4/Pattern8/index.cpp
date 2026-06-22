// -----------------------------------------------------------------------------
// Learning focus: Pattern8
// Purpose: Prints the Pattern8 console pattern using nested loops.
// Core idea: The outer loop selects a row; inner loops calculate that row's spaces, symbols, letters, or numbers.
// Complexity note: For an n-by-n style pattern, time is O(n^2); only loop counters use extra space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// 1
// 23
// 345

#include <iostream>
using namespace std;
int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << i + j + 1;
        }
        cout << endl;
    }
}