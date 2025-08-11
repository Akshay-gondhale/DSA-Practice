// AAA
// BBB
// CCC

#include <iostream>
using namespace std;

int main()
{
    char initChar = 'A';
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << initChar;
        }
        cout << endl;
        initChar++;
    }
}