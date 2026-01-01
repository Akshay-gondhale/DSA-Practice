// https://www.naukri.com/code360/problems/sum-of-two-arrays_893186?leftPanelTabValue=PROBLEM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
void printArr(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
void findArraySum(vector<int> &a, vector<int> &b)
{
    int sumOfArr1 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sumOfArr1 += pow(10, a.size() - i - 1) * a[i];
    }
    int sumOfArr2 = 0;
    for (int i = 0; i < b.size(); i++)
    {
        sumOfArr2 += pow(10, b.size() - i - 1) * b[i];
    }
    int sum = sumOfArr1 + sumOfArr2;

    vector<int> returnVector;
    while (sum > 0)
    {
        int lastDigit = sum % 10;
        returnVector.push_back(lastDigit);
        sum = sum / 10;
    }

    reverse(returnVector.begin(), returnVector.end());
    printArr(returnVector);
}
int main()
{
    vector<int> nums1;
    int size1;
    cout << "Enter array1 size: ";
    cin >> size1;
    cout << "Enter array1: ";
    for (int i = 0; i < size1; i++)
    {
        int input;
        cin >> input;
        nums1.push_back(input);
    }
    cout << endl;

    vector<int> nums2;
    int size2;
    cout << "Enter array2 size: ";
    cin >> size2;
    cout << "Enter array2: ";
    for (int i = 0; i < size2; i++)
    {
        int input;
        cin >> input;
        nums2.push_back(input);
    }
    cout << endl;
    findArraySum(nums1, nums2);
}