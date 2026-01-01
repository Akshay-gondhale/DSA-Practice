// https : // leetcode.com/problems/rotate-array/submissions/1863284025/
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
void rotateArray(vector<int> nums, int k)
{
    vector<int> rotatedArr(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        // EXPLAINATION FOR THIS LINE:
        // mod of n always gives a number between 0 to n-1
        // for case 1 (normal case):
        // [0, 1, 2, 3]
        // new position for index 1 with k = 2 will be:
        // (1 + 2) % 4 = 3 % 4 = 3
        // case 2 (last elems of array):
        // new position of 3rd index will be:
        // (3 + 2) % 4 = 5 % 4 = 1
        int newIndex = (i + k) % nums.size();
        rotatedArr[newIndex] = nums[i];
    }
    nums = rotatedArr;
    printArr(rotatedArr);
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
    rotateArray(nums, 2);
}