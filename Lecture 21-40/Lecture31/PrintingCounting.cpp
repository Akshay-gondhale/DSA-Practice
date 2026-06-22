// -----------------------------------------------------------------------------
// Learning focus: Printing Counting
// Purpose: Demonstrates Printing Counting through recursion.
// Core idea: A base case handles the smallest input; each recursive call reduces the problem and the returning calls combine or print results.
// Complexity note: Recursion depth and time follow the amount by which each call reduces the input.
// -----------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// Demonstrates how code placed before versus after a recursive call changes output order.
void printingAscending(int num)
{
    if (num <= 0)
    {
        return;
    }
    cout << num << endl;
    printingAscending(num - 1);
}
// Demonstrates how code placed before versus after a recursive call changes output order.
void printingDescending(int num)
{
    if (num <= 0)
    {
        return;
    }
    cout << num << endl;
    printingDescending(num - 1);
}
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << endl;
    // printingAscending(num);
    printingDescending(num);
}
