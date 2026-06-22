// -----------------------------------------------------------------------------
// Learning focus: Reverse An Array
// Purpose: Demonstrates Reverse An Array using in-place element swaps.
// Core idea: Move indices from the relevant ends or neighboring positions and swap each required pair exactly once.
// Complexity note: Time is O(n) and auxiliary space is O(1).
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
// Reverses the requested sequence or range by exchanging characters/elements from opposite ends.
void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    // Key idea: Move both boundaries inward after each swap so every pair is processed once.
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int numArr[size];
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }
    cout << endl;
    cout << "You entered: " << endl;
    printArray(numArr, size);
    cout << endl;

    reverseArray(numArr, size);
    cout << "Reversed Array: " << endl;
    printArray(numArr, size);
    cout << endl;
}
