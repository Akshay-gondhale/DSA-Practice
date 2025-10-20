// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
#include <iostream>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findPeak(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        int mid = start + ((end - start) / 2);
        int midLeft = mid - 1;
        int midRight = mid + 1;
        cout << midLeft << "--" << mid << "--" << midRight << endl;
        cout << arr[midLeft] << "--" << arr[mid] << "--" << arr[midRight] << endl;
        if (arr[midLeft] < arr[mid] && arr[mid] > arr[midRight])
        {
            return mid;
        }
        else
        {
            if (arr[midRight] > arr[mid])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
    }
    return -1;
}
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int numArr[size];
    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }
    int peak = findPeak(numArr, size);
    cout << peak;
}