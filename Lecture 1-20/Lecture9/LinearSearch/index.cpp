// -----------------------------------------------------------------------------
// Learning focus: Linear Search
// Purpose: Implements Linear Search by checking elements one at a time.
// Core idea: Stop when the target is found; otherwise continue until the searchable range is exhausted.
// Complexity note: Worst-case time is O(n); iterative extra space is O(1), while recursion uses O(n) stack space.
// -----------------------------------------------------------------------------
#include <iostream>
using namespace std;
// Searches elements in traversal order and returns as soon as the target is found.
bool linearSearch(int arr[], int size, int keyToSearch)
{

    // Key idea: If the current value is not the target, continue with the remaining range.
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == keyToSearch)
        {
            return true;
        }
    }

    return false;
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
    int keyToSearch;
    cout << "Enter key to search: ";
    cin >> keyToSearch;

    bool result = linearSearch(numArr, size, keyToSearch);
    if (result)
    {
        cout << keyToSearch << " found in array." << endl;
    }
    else
    {
        cout << keyToSearch << " not found in array." << endl;
    }
}
