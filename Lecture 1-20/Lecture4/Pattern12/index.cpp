// -----------------------------------------------------------------------------
// Learning focus: Pattern12
// Purpose: Prints the Pattern12 console pattern using nested loops.
// Core idea: The outer loop selects a row; inner loops calculate that row's spaces, symbols, letters, or numbers.
// Complexity note: For an n-by-n style pattern, time is O(n^2); only loop counters use extra space.
// -----------------------------------------------------------------------------
// ABC
// BCD
// CDE

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    // Key idea: The outer loop controls rows; nested loops derive the spaces and symbols required for each row.
    for (int i = 0; i < n; i++)
    {
        char initChar = 'A' + i;
        for (int j = 0; j < n; j++)
        {
            char localCh = initChar + j;
            cout << localCh;
        }
        cout << endl;
    }
}
