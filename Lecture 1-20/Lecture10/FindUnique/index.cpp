// -----------------------------------------------------------------------------
// Learning focus: Find Unique
// Purpose: Solves Find Unique by exploiting value-frequency or XOR cancellation properties.
// Core idea: The algorithm combines or counts values so matching occurrences cancel or become detectable.
// Complexity note: Inspect the implementation for its input assumptions; the main traversal is typically O(n).
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// to find unique element in array
// https://www.naukri.com/code360/problems/find-unique_625159
#include <iostream>
using namespace std;
// int findUniqueElement(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         bool isFound = false;
//         for (int j = 0; j < size; j++)
//         {
//             if (i == j)
//             {
//                 continue;
//             }
//             if (arr[i] == arr[j])
//             {
//                 isFound = true;
//                 break;
//             }
//         }

//         if (!isFound)
//         {
//             return arr[i];
//             break;
//         }
//     }

//     return -1;
// }

// alternate best solution from discussion and tutorial:
// utilizing bit wise XOR
// in XOR a ^ a results 0
// so thats why if we find XOR of every number all duplicates will be removed and only single unique number will remain

int findUniqueElement(int arr[], int size)
{
    int ans = 0;
    // for initial -> anything with XOR gives that thing only. i.e. a ^ 0 => a
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
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
    int uniqueNum = findUniqueElement(numArr, size);
    cout << "Unique number in given array is: " << uniqueNum << endl;
}