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
void selectionSort(int numArr[], int size)
{
    cout << endl;
    cout << "Given array: ";
    printArr(numArr, size);
    for (int i = 0; i < size; i++)
    {
        int smallNumIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (numArr[j] < numArr[smallNumIndex])
            {
                smallNumIndex = j;
            }
        }
        swap(numArr[i], numArr[smallNumIndex]);
    }
    cout << "Sorted array: ";
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
    selectionSort(numArr, size);
}