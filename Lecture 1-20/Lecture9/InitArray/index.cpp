// -----------------------------------------------------------------------------
// Learning focus: Init Array
// Purpose: Demonstrates Init Array and shows the data flow through a complete example.
// Core idea: Follow the helper functions first, then main(), which prepares input and displays the result.
// Complexity note: Complexity depends on the loops and helper functions identified below.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;
// Displays the supplied data without changing it; useful for checking the algorithm's result.
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int testArray[5] = {4, 2, 7, 5, 1};

    // printing array
    printArray(testArray, 5);
}
