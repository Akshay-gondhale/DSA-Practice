#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    cout << a << endl;
    cout << sizeof(a) << endl;
    cout << endl;
    char ch = 'a';
    cout << ch << endl;
    cout << sizeof(ch) << endl;
    cout << endl;
    bool boolVar = false;
    cout << boolVar << endl;
    cout << sizeof(boolVar) << endl;

    // type casting
    int intA = 'a';
    cout << intA << endl;
    cout << endl;

    char chB = 98;
    cout << chB << endl;
    cout << endl;

    // unsigned int
    unsigned int int2 = 98;
    cout << int2 << endl;
    cout << endl;
    unsigned int int3 = -98;
    cout << int3 << endl;
    cout << endl;
}

/*
NOTES :
1. If larger number stored in different data type var then only last bits will be taken in typecasting
2. Negative numbers have binary starting from 1
3. unsigned int will only store +ve number. If stored negetive then some large number will come in ouput as starting bit 1 will be considered as positive number
*/