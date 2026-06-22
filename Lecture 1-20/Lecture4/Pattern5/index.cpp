// -----------------------------------------------------------------------------
// Learning focus: Pattern5
// Purpose: Prints the Pattern5 console pattern using nested loops.
// Core idea: The outer loop selects a row; inner loops calculate that row's spaces, symbols, letters, or numbers.
// Complexity note: For an n-by-n style pattern, time is O(n^2); only loop counters use extra space.
// -----------------------------------------------------------------------------
// 123
// 456
// 789

#include <iostream>
using namespace std;
int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;
    int counter = 1;
    // Key idea: The outer loop controls rows; nested loops derive the spaces and symbols required for each row.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << counter;
            counter++;
        }
        cout << endl;
    }
}
