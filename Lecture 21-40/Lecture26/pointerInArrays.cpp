#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {23, 122, 41, 67};
    // address of array variable always points to first element's address. Thats why arr address and first elements address is same.
    cout << "Address of arr is " << arr << endl;
    cout << "First element is: " << arr[0] << endl;
    cout << "Address of first element is: " << &arr[0] << endl;
    cout << endl;
    // if we want to get second index by array pointer the we can do as follows:
    cout << "Second element using pointer is: " << *(arr + 1) << endl;
    cout << "Address of second element is: " << (arr + 1) << endl; // this will be previour pointer address + 4 bytes
    cout << endl;
    cout << "Adding 1 in 0th index using pointer:  " << *arr + 1 << endl;
    cout << endl;
    // another way of getting array index:
    int indexNum = 3;
    cout << "indexNum[arr] i.e. 3[arr] is: " << indexNum[arr] << endl;
    cout << endl;
    // getting size of array pointers and addresses
    int arr2[2] = {3, 4};
    cout << "Size of pointer stored in arr2: " << sizeof(arr2) << endl;
    cout << "Size of element stored in arr2[0]: " << sizeof(*arr2) << endl;
    cout << "&arr2 give address so its similar to only arr2 thats why its having exact same size of pointer: " << sizeof(&arr2) << endl;
    cout << endl;
    // storing index address in pointer variable
    int *indexOnePtr = &arr2[1];
    cout << "Address of index 1 in arr2 from pointer variable: " << indexOnePtr << endl;
    cout << "Address of index 1 in arr2 from actual array: " << (arr2 + 1) << endl;
    cout << "Address of arr2 variable which stores pointer of arr2: " << &arr2 << endl;
}