#include <iostream>
#include <algorithm>
using namespace std;
void printArr(int numArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int numArr[], int size)
{
    cout << "Before sorting array: " << endl;
    printArr(numArr, size);
    for (int i = 0; i < size; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (numArr[j] > numArr[j + 1])
            {
                isSwapped = true;
                swap(numArr[j], numArr[j + 1]);
            }
        }
        if (!isSwapped)
        {
            break;
        }
    }
    cout << "After sorting array: " << endl;
    printArr(numArr, size);
}
int main()
{
    int size;
    cout << "Enter array length: ";
    cin >> size;
    int numArr[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }
    bubbleSort(numArr, size);
}