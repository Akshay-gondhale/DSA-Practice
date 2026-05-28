#include <bits/stdc++.h>
using namespace std;

// here start is an default argument if nothing passed it will take 0
void printArray(int arr[], int size, int start = 0)
{
    for (int i = start; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    printArray(arr, 5, 3);
}