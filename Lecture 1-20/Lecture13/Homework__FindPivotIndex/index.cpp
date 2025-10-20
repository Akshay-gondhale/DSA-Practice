// https://leetcode.com/problems/find-pivot-index/description/
#include <iostream>
#include <vector>
using namespace std;
int sumOfArr(int arr[], int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{

    int size;
    cout << "Enter array size: ";
    cin >> size;
    int numArr[size];
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }

    int rightSum = sumOfArr(numArr, 0, size - 1);
    int leftSum = 0;
    for (int i = 0; i < size; i++)
    {
        int rightRemaining = rightSum - numArr[i];
        if (rightRemaining == leftSum)
        {
            cout << i << endl;
        }
        rightSum = rightRemaining;
        leftSum += numArr[i];
    }
}
