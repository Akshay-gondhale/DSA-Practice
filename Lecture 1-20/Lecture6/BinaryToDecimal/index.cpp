// this convert binary number to decimal
// eg: 1010 -> 10
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num;
    cout << "Enter a binary number: ";
    cin >> num;
    int i = 0;
    int ans = 0;
    while (num > 0)
    {
        int digit;
        digit = num % 10;
        if (digit == 1)
        {
            ans += pow(2, i);
        }
        i++;
        num = num / 10;
    }
    cout << "Number is: " << ans << endl;
}