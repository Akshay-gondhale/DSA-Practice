#include <bits/stdc++.h>
using namespace std;
void sayDigit(int n)
{
    if (n == 0)
    {
        return;
    }
    string numbers[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    sayDigit(n / 10);
    int lastDigit = n % 10;
    cout << numbers[lastDigit] << " ";
}
int main()
{
    sayDigit(506);
}