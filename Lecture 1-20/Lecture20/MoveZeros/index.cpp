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

void moveZeros(vector<int> &nums)
{
    int i = 0; // for nums
    int j = 0; // for zeros
    while (i < nums.size() && j < nums.size())
    {
        if (i == j && nums[i] != 0)
        {
            if (nums[i] != 0)
            {
                // moving both pointers if they are on same location and num
                // is non zero
                i++;
                j++;
                continue;
            }
            else
            {

                // only moving i if both i and j are on same location and
                // its zero
                i++;
                continue;
            }
        }
        else
        {
            // swaping if i is not equal to j and i is non zero
            if (nums[i] == 0)
            {
                i++;
                continue;
            }
            else
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
                continue;
            }
        }
    }
    printArr(nums);
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

    moveZeros(nums);
}