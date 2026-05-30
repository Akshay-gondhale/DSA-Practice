#include <bits/stdc++.h>
using namespace std;
void printingAscending(int num)
{
    if (num <= 0)
    {
        return;
    }
    cout << num << endl;
    printingAscending(num - 1);
}
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