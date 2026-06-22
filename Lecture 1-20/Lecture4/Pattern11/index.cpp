// -----------------------------------------------------------------------------
// Learning focus: Pattern11
// Purpose: Prints the Pattern11 console pattern using nested loops.
// Core idea: The outer loop selects a row; inner loops calculate that row's spaces, symbols, letters, or numbers.
// Complexity note: For an n-by-n style pattern, time is O(n^2); only loop counters use extra space.
// -----------------------------------------------------------------------------
// D
// CD
// BCD
// ABCD

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    char initChar = 'A';
    // Key idea: The outer loop controls rows; nested loops derive the spaces and symbols required for each row.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            char localCh = initChar + n + j - i - 1;
            cout << localCh;
        }
        cout << endl;
    }
}
