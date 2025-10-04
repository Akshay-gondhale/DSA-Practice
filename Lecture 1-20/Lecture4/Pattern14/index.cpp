//   1
//  121
// 12321

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        // spaces
        for (int s = 0; s < num - i - 1; s++)
        {
            cout << " ";
        }
        // left triangle
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1;
        }
        // right triangle
        for (int k = i; k > 0; k--)
        {
            cout << k;
        }
        cout << endl;
    }
}