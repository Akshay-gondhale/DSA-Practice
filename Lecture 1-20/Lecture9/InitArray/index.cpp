#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int testArray[5] = {4, 2, 7, 5, 1};

    // printing array
    printArray(testArray, 5);
}