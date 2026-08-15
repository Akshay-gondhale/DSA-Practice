#include <bits/stdc++.h>
using namespace std;

//*  Inheritance Ambiguity:
//
//*          Animals          Mammals
//*             \              /
//*              \            /
//*                 Humans
//*
//?  Humans inherits from both Animals and Mammals.
//?  Both base classes contain a function named speaking().
//?  When Humans tries to call speaking() directly, the compiler cannot determine
//*  which base class function should be invoked.
//?  This situation is called Inheritance Ambiguity.
//?  Scope Resolution Operator (::) can be used to explicitly specify the
//*  base class whose function should be called.

//*  Animals is one of the base classes of Humans.
class Animals
{
public:
    string kingdom;
    string species;
    bool isHerbivorous;

    void speaking()
    {
        cout << "Animals can speak" << endl;
    }
};

//*  Mammals is another base class of Humans.
class Mammals
{
public:
    bool haveFur;
    int walkOnNumOfLegs;

    void speaking()
    {
        cout << "Mammals can speak" << endl;
    }
};

//*  Humans inherits from both Mammals and Animals.
//?  Both base classes provide a speaking() function with the same name.
//?  Therefore, calling akshay.speaking() directly creates an ambiguity because
//*  the compiler cannot decide whether Animals::speaking() or Mammals::speaking()
//*  should be called.
class Humans : public Mammals, public Animals
{
public:
    string name;
    char gender;

    Humans(string &name, char gender)
    {
        this->name = name;
        this->gender = gender;
        this->haveFur = false;
        this->isHerbivorous = false;
        this->kingdom = "Animalia";
        this->species = "Homo Sepians";
        this->walkOnNumOfLegs = 4;
    }

    void printHumanDetails()
    {
        cout << "[name: " << this->name
             << ", gender: " << this->gender
             << ", haveFur: " << this->haveFur
             << ", isHerbivorous: " << this->isHerbivorous
             << ", kingdom: " << this->kingdom
             << ", species: " << this->species
             << ", walkOnNumOfLegs: " << this->walkOnNumOfLegs
             << "]" << endl;
    }
};

int main()
{
    string humanName = "akshay";
    Humans akshay(humanName, 'M');

    akshay.printHumanDetails();

    //?  Both Animals and Mammals have a speaking() function.
    //?  Calling it directly results in inheritance ambiguity.
    // akshay.speaking(); // error

    //*  Scope Resolution Operator (::) explicitly specifies the base class.
    //*  Here, Mammals::speaking() is invoked.
    akshay.Mammals::speaking();
}