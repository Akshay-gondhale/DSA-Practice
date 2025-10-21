// https://leetcode.com/problems/sqrtx/description/
#include <iostream>
using namespace std;
int findSqrt(int x)
{
    if (x == 0)
    {
        return 0;
    }
    if (x == 1)
    {
        return 1;
    }
    int start = 0;
    int end = x;
    long long int ans = -1;
    while (start < end)
    {
        long long int mid = start + (end - start) / 2;
        long long int square = mid * mid;
        if (square == x)
        {
            return mid;
        }
        else
        {
            if (square < x)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
    }
    return ans;
}
int main()
{
    int num;
    cout << "Enter a number to find sqrt of it: ";
    cin >> num;
    int sqrt = findSqrt(num);
    cout << "Square root of " << num << " is: " << sqrt << endl;
}