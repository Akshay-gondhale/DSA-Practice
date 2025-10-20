#include <iostream>
using namespace std;
int sumOfArr(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
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
    int sum = sumOfArr(numArr, size);
    cout << "Sum of all numbers is: " << sum << endl;
}