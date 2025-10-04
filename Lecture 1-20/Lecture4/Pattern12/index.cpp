// ABC
// BCD
// CDE

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char initChar = 'A' + i;
        for (int j = 0; j < n; j++)
        {
            char localCh = initChar + j;
            cout << localCh;
        }
        cout << endl;
    }
}