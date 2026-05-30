#include <bits/stdc++.h>
using namespace std;
int getTwosPower(int n)
{
    if (n <= 1)
    {
        return 2;
    }
    return 2 * getTwosPower(n - 1);
}
int main()
{
    int power;
    cout << "Enter a power number for 2: ";
    cin >> power;
    int result = getTwosPower(power);
    cout << "2s power " << power << " is " << result << endl;
}