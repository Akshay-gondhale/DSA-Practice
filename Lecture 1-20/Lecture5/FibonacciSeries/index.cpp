#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num <= 2)
    {
        cout << "Please enter a number greater than 2" << endl;
        return 0;
    }
    int a = 0;
    int b = 1;
    cout << a << " " << b << " ";
    for (int i = 2; i < num; i++)
    {
        int nextNumber = a + b;
        cout << nextNumber << " ";
        a = b;
        b = nextNumber;
    }
}