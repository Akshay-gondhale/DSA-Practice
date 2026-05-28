#include <bits/stdc++.h>
using namespace std;

// if your function haves only 1 line then you can convert it to inline function.
// compiler its occurance too with single line code before compilation
inline int getMax(int &a, int &b) { return (a > b) ? a : b; }
int main()
{
    int a = 4, b = 5;
    int ans = getMax(a, b);
    cout << ans << endl;
}