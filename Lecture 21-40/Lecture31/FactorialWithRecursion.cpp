#include <bits/stdc++.h>
using namespace std;
int factorial(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    return num * factorial(num - 1);
}
int main()
{
    int num;
    cout << "Enter an number to get factorial: ";
    cin >> num;
    int result = factorial(num);
    cout << num << "! = " << result << endl;
}