#include <bits/stdc++.h>
using namespace std;

//*  Multilevel Inheritance:
//
//*      Animals
//*         |
//*        Dog
//*         |
//*       Husky
//
//?  Each derived class inherits from the class directly above it.
//?  Husky inherits from Dog and indirectly gets the public members of Animals.
//?  This chain of inheritance (Animals → Dog → Husky) demonstrates Multilevel Inheritance.

//*  Animals is the base class at the first level of the inheritance hierarchy.
class Animals
{
public:
    string species;
    int numOfLegs;
    void speaking()
    {
        cout << "Animal is speaking" << endl;
    }
};

//*  Dog inherits from Animals, forming the second level of the inheritance hierarchy.
//?  Dog can access the public members inherited from Animals.
class Dog : public Animals
{
public:
    string name;
    Dog()
    {
        this->species = "mammals";
        this->numOfLegs = 4;
    }
    void barking()
    {
        cout << "Bhaw bhaw" << endl;
    }
};

//*  Husky inherits from Dog, forming the third level of the inheritance hierarchy.
//?  Husky indirectly inherits the public members of Animals through Dog.
class Husky : public Dog
{
public:
    Husky(string &name)
    {
        this->species = "Dog";
        this->name = name;
    }
};
int main()
{
    string dogName = "jack";
    Husky myDog(dogName);
    cout << "My dog name is: " << myDog.name << endl;
    cout << "My dog's species: " << myDog.species << endl;
    myDog.barking();
    myDog.speaking();
}