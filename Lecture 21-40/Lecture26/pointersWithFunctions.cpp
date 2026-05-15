#include <bits/stdc++.h>
using namespace std;
void print(int *p)
{
    cout << "Value of pointer in function is: " << *p << endl;
}

void update(int *p)
{
    // if we update pointer address it will not affect main.
    // p = p + 1;
    // cout << "inside "<< p <<endl;
    // but if we update its value then it will modify main value
    *p = *p + 1;
}

int getSum(int *arr, int n)
{

    // this prints size of pointer as 8
    // cout << "Size : " << sizeof(arr) << endl;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int value = 5;
    int *p = &value;
    print(p);
    cout << endl;
    cout << "Checking if updating pointer value in function can change is address?" << endl;
    cout << "Before: " << *p << endl;
    update(p);
    cout << "After: " << *p << endl;
    cout << endl;
    // printing array sum from middle of array using pointers

    int arr[6] = {1, 2, 3, 4, 5, 8};

    cout << "Sum is: " << getSum(arr + 3, 3) << endl;
}