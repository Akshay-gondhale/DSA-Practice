// -----------------------------------------------------------------------------
// Learning focus: Homework: Sum Of All
// Purpose: Demonstrates Homework: Sum Of All and shows the data flow through a complete example.
// Core idea: Follow the helper functions first, then main(), which prepares input and displays the result.
// Complexity note: Complexity depends on the loops and helper functions identified below.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;
int sumOfArr(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int numArr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }
    int sum = sumOfArr(numArr, size);
    cout << "Sum of all numbers is: " << sum << endl;
}