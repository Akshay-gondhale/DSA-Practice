// https://leetcode.com/problems/power-of-two/submissions/1791445319/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;
    int i = 0;
    bool isPowerOfTwo = false;

    while (i < 32)
    {
        int power = pow(2, i);
        if (power > num)
        {
            break;
        }
        if (power == num)
        {
            isPowerOfTwo = true;
            break;
        }
        i++;
    }
    cout << isPowerOfTwo << endl;
}