// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
#include <iostream>
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
void checkIfArrayIsSortedAndRotated1(vector<int> &nums)
{
    // x is to find how much array is rotated
    // initially it will be 0 considering default is sorted
    int x = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            x = nums.size() - (i + 1);
        }
    }
    if (x == 0)
    {
        // returning true if array is completely sorted
        cout << "true" << endl;
    }
    // rotating back array
    vector<int> rotatedArr(nums.size());
    for (int j = 0; j < nums.size(); j++)
    {
        // explaination mentiond in que no 189
        int newIndex = (j + x) % nums.size();
        rotatedArr[newIndex] = nums[j];
    }
    // checking if rotated array is completely sorted
    bool isSorted = true;
    for (int k = 0; k < rotatedArr.size() - 1; k++)
    {
        if (rotatedArr[k] > rotatedArr[k + 1])
        {
            isSorted = false;
            break;
        }
    }
    cout << isSorted << endl;
}
void checkIfArrayIsSortedAndRotated2(vector<int> &nums)
{

    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] < nums[i])
        {
            count++;
        }
    }
    // if you plot graph of rotating array it will show two parallel lines.
    // which indicates that second line last element(last index of array)
    // should be always less than first line begining (first index of array)
    if (nums[nums.size() - 1] > nums[0])
    {
        count++;
    }
    cout << (count <= 1) << endl;
}

int main()
{
    vector<int> nums;
    int size;
    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        int input;
        cin >> input;
        nums.push_back(input);
    }
    cout << endl;
    checkIfArrayIsSortedAndRotated2(nums);
}