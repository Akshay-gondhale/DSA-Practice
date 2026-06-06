#include <bits/stdc++.h>
using namespace std;
// unoptimised
// int calculatePower(int num, int power)
// {
//     if (power == 0)
//     {
//         return 1;
//     }
//     if (power == 1)
//     {
//         return num;
//     }
//     return num * calculatePower(num, power - 1);
// }

// optimised
int calculatePower(int num, int power)
{
    if (power == 0)
    {
        return 1;
    }
    if (power == 1)
    {
        return num;
    }
    int ans = calculatePower(num, power / 2);
    if (power % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return num * ans * ans;
    }
}
int main()
{
    int num = 5;
    int power = 2;
    int result = calculatePower(num, power);
    cout << result << endl;
}