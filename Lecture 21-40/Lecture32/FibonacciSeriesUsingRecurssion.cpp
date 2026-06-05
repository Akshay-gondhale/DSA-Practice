// https://leetcode.com/problems/fibonacci-number/description/
#include <bits/stdc++.h>
using namespace std;

int getNthFibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return getNthFibonacci(n - 1) + getNthFibonacci(n - 2);
}
int main()
{
    int input;
    cout << "Enter a number to get fibonacci of that position: ";
    cin >> input;
    int result = getNthFibonacci(input);
    cout << "Result: " << result << endl;
}