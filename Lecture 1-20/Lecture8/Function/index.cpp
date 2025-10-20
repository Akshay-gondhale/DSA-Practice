// nCr formula with functions
// Formula:
// nCr = n!/r!(n-r)!

#include <iostream>
using namespace std;
int factorial(int num)
{
    int ans = 1;
    for (int i = num; i > 0; i--)
    {
        ans = ans * i;
    }
    return ans;
}
int ncrFormula(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int main()
{
    cout << ncrFormula(3, 2) << endl;
}