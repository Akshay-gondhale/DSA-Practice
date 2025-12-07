#include <iostream>
#include <vector>
using namespace std;
// * Benefit of using vector is it is now size bounded. It expands if you push
// * more elements in it. Each time when limit gets exhaust it doubles its length.

void printVector(vector<int> numArr)
{
    for (int i = 0; i < numArr.size(); i++)
    {
        cout << numArr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // declaring simple int vector
    vector<int> numArr;

    // checking capacity of empty vector.
    cout << "Initial capacity of numArr: " << numArr.capacity() << endl;
    cout << "Initial size of numArr: " << numArr.size() << endl;
    cout << endl;
    // to append elements we use push_back() method.
    numArr.push_back(1);
    cout << "Capacity of numArr after pushing element 1: " << numArr.capacity() << endl;
    cout << "Size of numArr after pushing element 1: " << numArr.size() << endl;
    cout << endl;
    // pushing few more elements
    numArr.push_back(2);
    cout << "Capacity of numArr after pushing element 2: " << numArr.capacity() << endl;
    cout << "Size of numArr after pushing element 2: " << numArr.size() << endl;
    cout << endl;

    // here it doubled its capacity from 2 to 4. Since for prev element array got full now if i pushed one more item it
    // needs to expand itself so it doubled its capacity
    numArr.push_back(3);
    cout << "Capacity of numArr after pushing element 3: " << numArr.capacity() << endl;
    cout << "Size of numArr after pushing element 3: " << numArr.size() << endl;
    cout << endl;

    cout << "Current vector: " << endl;
    printVector(numArr);
    cout << endl;

    // accessing nth vector element
    cout << "Second element is: " << numArr[1] << endl;
    cout << endl;

    // accessing elements using at() method
    // accessing nth vector element
    cout << "Second element using at() is: " << numArr.at(1) << endl;
    cout << endl;

    // checking if vector is empty
    cout << "Is vector empty? == " << numArr.empty() << endl;
    cout << endl;

    // first and last element of vector
    cout << "First element: " << numArr.front() << endl;
    cout << "Last element: " << numArr.back() << endl;
    cout << endl;

    // popping out last element of vector using pop_back
    numArr.pop_back();
    cout << "Vector after popping last element: " << endl;
    printVector(numArr);
    cout << endl;

    // another way to init vector
    // here 5 is vector size and all elements will be 1.
    vector<int> numArr2(5, 1);
    cout << "Vector 2:" << endl;
    printVector(numArr2);
    cout << endl;

    // to copy one vector in another
    vector<int> numArrCopy(numArr2);
    cout << "Copy of vector 2:" << endl;
    printVector(numArrCopy);
}