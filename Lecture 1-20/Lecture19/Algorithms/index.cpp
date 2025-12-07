#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printArr(vector<int> numArr)
{
    for (int i = 0; i < numArr.size(); i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> numArr = {1, 2, 3, 4, 5};
    // binary search algo
    cout << "Searching if 4 is present using binary search in numsArr. Result: " << binary_search(numArr.begin(), numArr.end(), 4) << endl;
    cout << "Searching if 6 is present using binary search in numsArr. Result: " << binary_search(numArr.begin(), numArr.end(), 6) << endl;
    cout << endl;

    cout << "Lower bound is: " << lower_bound(numArr.begin(), numArr.end(), 3) - numArr.begin() << endl;
    cout << "Upper bound is: " << upper_bound(numArr.begin(), numArr.end(), 3) - numArr.begin() << endl;
    cout << endl;
    int a = 3;
    int b = 4;
    cout << "Before swap values = a: " << a << " b: " << b << endl;
    swap(a, b);
    cout << "After swap values = a: " << a << " b: " << b << endl;
    cout << endl;
    string strData = "abcd";
    cout << "before reversing string: " << strData << endl;
    reverse(strData.begin(), strData.end());
    cout << "After reversing string: " << strData << endl;
    // rotating algorithm
    cout << "Before rotating numArr values: " << endl;
    printArr(numArr);
    rotate(numArr.begin(), numArr.begin() + 2, numArr.end());
    cout << "After rotating numArr values: " << endl;
    printArr(numArr);
}