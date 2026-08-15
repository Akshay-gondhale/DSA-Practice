#include <bits/stdc++.h>
using namespace std;

//*  Single Inheritance:
//
//*        Human
//*          |
//*         Male
//
//?  A single derived class inherits from a single base class.
//?  Male inherits the public members of Human.

//*  Human is the base (parent) class.
class Human
{
public:
    int age;

    void speaking()
    {
        cout << "Speaking" << endl;
    }
};

//*  Male is the derived (child) class.
//?  It inherits Human publicly, so its public members are accessible through Male objects.
class Male : public Human
{
public:
    void greet()
    {
        cout << "Hello programmer" << endl;
    }
};

int main()
{
    //*  Male object can access its own members as well as inherited public members of Human.
    Male akshay;
    akshay.greet();
    akshay.speaking();
}