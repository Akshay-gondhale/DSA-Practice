// -----------------------------------------------------------------------------
// Learning focus: Linear Search In2 DArray
// Purpose: Implements Linear Search In2 DArray by checking elements one at a time.
// Core idea: Stop when the target is found; otherwise continue until the searchable range is exhausted.
// Complexity note: Worst-case time is O(n); iterative extra space is O(1), while recursion uses O(n) stack space.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;

bool linearSearch2DArray(int arr[][4], int rowSize, int elementToSearch)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == elementToSearch)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int numArr[3][4];
    cout << "Enter 12 elements for array of 3x4: " << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            cin >> numArr[row][column];
        }
    }
    cout << endl;
    cout << "Print 2D array:" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            cout << numArr[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Enter element to search: ";
    int elementToSearch;
    cin >> elementToSearch;
    bool isPresent = linearSearch2DArray(numArr, 3, elementToSearch);
    cout << "Is " << elementToSearch << " present in given array: " << isPresent << endl;
}