// -----------------------------------------------------------------------------
// Learning focus: Count Ways To Reach NStair
// Purpose: Demonstrates Count Ways To Reach NStair through recursion.
// Core idea: A base case handles the smallest input; each recursive call reduces the problem and the returning calls combine or print results.
// Complexity note: Recursion depth and time follow the amount by which each call reduces the input.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650
#include <bits/stdc++.h>
using namespace std;
int countDistance(int n)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    return countDistance(n - 1) + countDistance(n - 2);
}
int main()
{
    cout << countDistance(5) << endl;
}