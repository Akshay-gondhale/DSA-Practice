// https://leetcode.com/problems/merge-sorted-array/description/
#include <iostream>
#include <vector>
using namespace std;
void printArr(vector<int> &numArr)
{
    for (int i = 0; i < numArr.size(); i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}

void mergeTwoSortedArray(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> mergedArray(m + n, 0);
    int i = 0; // pointer for nums1 array
    int j = 0; // pointer for nums2 array
    int k = 0; // pointer for merged array
    while (i < m && j < n && k < m + n)
    {
        if (nums1[i] < nums2[j])
        {
            mergedArray[k] = nums1[i];
            i++;
        }
        else
        {
            mergedArray[k] = nums2[j];
            j++;
        }
        k++;
    }
    // copying remaining elements of both the arrays as it is at the end
    if (i < m)
    {
        for (; i < m; i++)
        {
            mergedArray[k] = nums1[i];
            k++;
        }
    }
    else
    {
        for (; j < n; j++)
        {
            mergedArray[k] = nums2[j];
            k++;
        }
    }
    printArr(mergedArray);
}
int main()
{
    vector<int> numArr1;
    int numArr1Size;
    vector<int> numArr2;
    int numArr2Size;
    cout << "Enter first array size: ";
    cin >> numArr1Size;
    cout << "Enter first array: ";
    for (int i = 0; i < numArr1Size; i++)
    {
        int input;
        cin >> input;
        numArr1.push_back(input);
    }
    cout << endl;
    // second
    cout << "Enter second array size: ";
    cin >> numArr2Size;
    cout << "Enter second array: ";
    for (int i = 0; i < numArr2Size; i++)
    {
        int input;
        cin >> input;
        numArr2.push_back(input);
    }
    printArr(numArr1);
    mergeTwoSortedArray(numArr1, numArr1Size, numArr2, numArr2Size);
}