// -----------------------------------------------------------------------------
// Learning focus: Pattern7
// Purpose: Prints the Pattern7 console pattern using nested loops.
// Core idea: The outer loop selects a row; inner loops calculate that row's spaces, symbols, letters, or numbers.
// Complexity note: For an n-by-n style pattern, time is O(n^2); only loop counters use extra space.
// -----------------------------------------------------------------------------
// 1
// 22
// 333

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
        for (int j = 0; j < i + 1; j++)
        {
            cout << i + 1;
        }
        cout << endl;
    }
}
