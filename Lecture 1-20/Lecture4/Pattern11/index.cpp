// D
// CD
// BCD
// ABCD

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    char initChar = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            char localCh = initChar + n + j - i - 1;
            cout << localCh;
        }
        cout << endl;
    }
}