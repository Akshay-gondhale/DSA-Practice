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