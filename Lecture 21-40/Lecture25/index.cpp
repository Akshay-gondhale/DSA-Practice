#include <iostream>
using namespace std;
int main()
{
    int testNum = 1;
    int *pointerOfTestNum = &testNum;
    cout << "testNum: " << testNum << endl;
    cout << "Address of testNum: " << &testNum << endl;
    cout << "Value stored inside pointer variable: " << pointerOfTestNum << endl;
    cout << "Value pointer pointing at: " << *pointerOfTestNum << endl;
    cout << endl;
    cout << endl;

    // increasing value using pointer
    cout << "testNum value before: " << testNum << endl;
    (*pointerOfTestNum)++;
    cout << "testNum value after: " << testNum << endl;

    cout << endl;
    // null pointer
    int *nullPointer = 0;
    // cout << *nullPointer << endl; // this will throw error or print nothing as pointer is not pointing to any value
    // assigning value to null pointer
    nullPointer = &testNum;
    cout << "Address stored in null pointer post assigning value: " << nullPointer << endl;

    cout << endl;
    int *copyNullPointer = pointerOfTestNum;
    cout << "Address stored in pointerOfTestNum: " << pointerOfTestNum << endl;
    cout << "Address stored in copyNullPointer: " << copyNullPointer << endl;
    cout << "Value copyNullPointer pointing at: " << *copyNullPointer << endl;
}