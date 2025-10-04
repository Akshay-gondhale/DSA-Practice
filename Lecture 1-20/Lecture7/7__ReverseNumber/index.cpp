// https://leetcode.com/problems/reverse-integer/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number to reverse: ";
    cin >> num;
    int ans = 0;
    while (num != 0)
    {
        ans = ans * 10;
        int digit = num % 10;
        cout << "digit: " << digit << endl;
        num = num / 10;
        ans += digit;
    }
    cout << ans << endl;
}