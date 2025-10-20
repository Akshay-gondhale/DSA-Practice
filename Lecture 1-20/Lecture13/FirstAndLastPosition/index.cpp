// https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
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
int findOcc(int arr[], int size, int key, int type)
{
    int start = 0;
    int end = size - 1;
    int mostRecentOcc;
    if (type == 0)
    {
        mostRecentOcc = size;
    }
    else
    {
        mostRecentOcc = 0;
    }
    bool isFound = false;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid] == key)
        {
            isFound = true;
            if (type == 0)
            {
                if (mostRecentOcc > mid)
                {
                    mostRecentOcc = mid;
                }
                end = mid - 1;
            }
            else
            {
                if (mostRecentOcc < mid)
                {
                    mostRecentOcc = mid;
                }
                start = mid + 1;
            }
        }
        else
        {
            if (arr[mid] > key)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    if (isFound)
    {

        return mostRecentOcc;
    }
    else
    {
        return -1;
    }
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
    int keyToSearch;
    cout << "Enter key to search: ";
    cin >> keyToSearch;
    int findOccNum = findOcc(numArr, size, keyToSearch, 1);
    cout << findOccNum << endl;
    return 0;
}