// alternate elements in array will be swaped
// eg:
// input: [1,2,3,4,5,6]
// output: [2,1,4,3,6,5]
#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void alternateSwap(int arr[], int size)
{
    for (int i = 0; i < size; i = i + 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
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
    cout << "You entered: " << endl;
    printArray(numArr, size);
    cout << endl;

    alternateSwap(numArr, size);
    cout << "Alternate Swapped Array: " << endl;
    printArray(numArr, size);
    cout << endl;
}