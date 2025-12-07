#include <iostream>
#include <array>
using namespace std;

// * Array remains constant in size once declared you cannot change it. This is the difference between array and vector
int main()
{
    // this is default array
    int basic[3] = {2, 3, 4};
    // declaring array with array STL.
    array<int, 3> numArr = {2, 3, 4};

    // here you will get size method to get arrays size
    cout << "Size of array is: " << numArr.size() << endl;

    // accessing nth array element
    cout << "Second element is: " << numArr[1] << endl;

    // accessing elements using at() method
    // accessing nth array element
    cout << "Second element using at() is: " << numArr.at(1) << endl;

    // checking if array is empty
    cout << "Is array empty? == " << numArr.empty() << endl;

    // first and last element of array
    cout << "First element: " << numArr.front() << endl;
    cout << "Last element: " << numArr.back() << endl;
}