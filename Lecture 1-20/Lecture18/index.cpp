// https://www.naukri.com/code360/problems/insertion-sort_3155179?source=youtube&campaign=love_babbar_codestudio2
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
void insertionSort(int numArr[], int size)
{
    // sample
    // 10 4 11 3
    cout << "Before sorting array: " << endl;
    printArr(numArr, size);
    for (int i = 1; i < size; i++)
    {
        int temp = numArr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (numArr[j] > temp)
            {
                // shifting if prev element is greater than current one.
                // for first rount j+1 will be i. And i is already stored in temp which will be safely replaced later.
                numArr[j + 1] = numArr[j];
            }
            else
            {
                // if prev element is less than current then no need to sort just break this loop.
                break;
            }
            // replacing temp on its correct position
        }
        numArr[j + 1] = temp;
        cout << "POST ROUND " << i << " STATUS: " << endl;
        printArr(numArr, size);
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
    insertionSort(numArr, size);
}