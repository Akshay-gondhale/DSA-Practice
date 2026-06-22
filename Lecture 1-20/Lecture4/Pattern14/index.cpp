// -----------------------------------------------------------------------------
// Learning focus: Pattern14
// Purpose: Prints the Pattern14 console pattern using nested loops.
// Core idea: The outer loop selects a row; inner loops calculate that row's spaces, symbols, letters, or numbers.
// Complexity note: For an n-by-n style pattern, time is O(n^2); only loop counters use extra space.
// -----------------------------------------------------------------------------
//   1
//  121
// 12321

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    // Key idea: The outer loop controls rows; nested loops derive the spaces and symbols required for each row.
    for (int i = 0; i < num; i++)
    {
        // spaces
        for (int s = 0; s < num - i - 1; s++)
        {
            cout << " ";
        }
        // left triangle
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1;
        }
        // right triangle
        for (int k = i; k > 0; k--)
        {
            cout << k;
        }
        cout << endl;
    }
}
