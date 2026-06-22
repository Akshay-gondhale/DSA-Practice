// -----------------------------------------------------------------------------
// Learning focus: 2 DArray Implementation
// Purpose: Demonstrates 2 DArray Implementation on a two-dimensional matrix.
// Core idea: Nested loops or moving boundaries determine the order in which rows and columns are visited.
// Complexity note: Visiting every matrix entry takes O(rows * columns) time.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
    // int numArr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int numArr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << "Print 2D array:" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            cout << numArr[row][column] << " ";
        }
        cout << endl;
    }
}