// https : // www.naukri.com/code360/problems/duplicate-in-array_893397?leftPanelTabValue=PROBLEM
#include <iostream>
using namespace std;
int findDuplicate(int arr[], int size)
{
    // Write your code here
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }

    for (int i = 1; i < size; i++)
    {
        ans = ans ^ i;
    }

    return ans;
}
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int numArr[size];
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }
    int duplicatedNum = findDuplicate(numArr, size);
    cout << "Duplicated number in array is: " << duplicatedNum << endl;
}