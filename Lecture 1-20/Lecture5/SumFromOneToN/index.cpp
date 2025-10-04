#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter an number: ";
    cin >> num;
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += i;
    }
    cout << "Total sum is: " << sum << endl;
}