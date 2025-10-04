// https://leetcode.com/problems/complement-of-base-10-integer/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int ans = ~num;
    int mask = 0;
    while (num != 0)
    {
        num = num >> 1;
        mask = mask << 1;
        mask = mask | 1;
    }

    ans = ans & mask;
    cout << ans;
}