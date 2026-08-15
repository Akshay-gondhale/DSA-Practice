#include <bits/stdc++.h>
using namespace std;

//*  Hierarchical Inheritance:
//
//*          A
//*         / \
//*        B   C
//
//?  Both B and C inherit from the same base class A.
//?  This inheritance structure is called Hierarchical Inheritance.
//?  Each derived class gets access to the public members of A independently.

//*  A is the common base (parent) class.
class A
{
public:
    void func1()
    {
        cout << "Function 1 from class A got fired" << endl;
    }
};

//*  B is a derived (child) class of A.
//?  B inherits the public members of A and also defines its own func2().
class B : public A
{
public:
    void func2()
    {
        cout << "Function 2 from class B got fired" << endl;
    }
};

//*  C is another derived (child) class of A.
//?  C also inherits the public members of A independently from B.
//?  B and C do not inherit from each other.
class C : public A
{
public:
    void func3()
    {
        cout << "Function 3 from class C got fired" << endl;
    }
};
int main()
{
    //*  B object can access both its own func2() and the inherited func1() from A.
    B object1;
    object1.func1();
    object1.func2();

    cout << endl;

    //*  C object can access both its own func3() and the inherited func1() from A.
    C object2;
    object2.func1();
    object2.func3();
}