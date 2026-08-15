#include <bits/stdc++.h>
using namespace std;

//*  Hybrid Inheritance:
//
//*              A
//*             / \
//*            B   C
//*                |
//*                D
//
//?  This hierarchy combines more than one type of inheritance.
//?  A → B represents Single Inheritance.
//?  A → C represents Single Inheritance.
//?  A → C → D represents Multilevel Inheritance.
//?  A → B and A → C together form Hierarchical Inheritance.
//?  The combination of these inheritance types is called Hybrid Inheritance.

//*  A is the common base (parent) class.
class A
{
public:
    void func1()
    {
        cout << "Function 1 from class A got fired" << endl;
    }
};

//*  B inherits from A.
//?  B can access the public members inherited from A.
class B : public A
{
public:
    void func2()
    {
        cout << "Function 2 from class B got fired" << endl;
    }
};

//*  C also inherits from A.
//?  A → B and A → C creates a Hierarchical Inheritance structure.
class C : public A
{
public:
    void func3()
    {
        cout << "Function 3 from class C got fired" << endl;
    }
};

//*  D inherits from C.
//?  C → D extends the hierarchy further, creating Multilevel Inheritance.
//?  D indirectly inherits the public members of A through C.
//?  The combination of Hierarchical and Multilevel Inheritance makes this a Hybrid Inheritance structure.
class D : public C
{
public:
    void func4()
    {
        cout << "Function 4 from class D got fired" << endl;
    }
};
int main()
{

    //*  B object can access its own func2() and the inherited func1() from A.
    B object1;
    object1.func1();
    object1.func2();

    cout << endl;

    //*  C object can access its own func3() and the inherited func1() from A.
    C object2;
    object2.func1();
    object2.func3();

    cout << endl;

    //*  D object can access its own func4(), func3() from C,
    //*  and func1() inherited indirectly from A through C.
    D object3;
    object3.func1();
    object3.func3();
    object3.func4();
}