#include <iostream>
#include <climits>
using namespace std;
int minInArray(int arr[], int size)
{
    int minNum = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        minNum = min(arr[i], minNum);
    }

    return minNum;
}
int maxInArray(int arr[], int size)
{
    int maxNum = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        maxNum = max(arr[i], maxNum);
    }

    return maxNum;
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
    int min = minInArray(numArr, size);
    int max = maxInArray(numArr, size);

    cout << "Max in array is: " << max << endl;
    cout << "Min in array is: " << min << endl;
}