// This program converts decimal to binary
// it only accepts positive number as of now
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    cout << "Enter a number: ";
    int num;
    cin >> num;

    int i = 0;
    int ans = 0;

    while (num != 0)
    {
        int bit = num & 1;
        ans = (bit * pow(10, i)) + ans;
        num = num >> 1;
        i++;
    }
    cout << ans << endl;
}