#include <bits/stdc++.h>
using namespace std;

//*  Multiple Inheritance:
//
//*       Animals        Mammals
//*           \            /
//*            \          /
//*               Humans
//
//?  Humans inherits from two independent base classes: Animals and Mammals.
//?  Inheriting from more than one base class is called Multiple Inheritance.
//?  Humans gets the public members of both Animals and Mammals.

//*  Animals is one of the base classes that provides animal-related properties.
class Animals
{
public:
    string kingdom;
    string species;
    bool isHerbivorous;
};

//*  Mammals is another independent base class that provides mammal-related properties.
class Mammals
{
public:
    bool haveFur;
    int walkOnNumOfLegs;
};

//*  Humans inherits from two independent base classes: Mammals and Animals.
//?  Humans gets the public members of both Mammals and Animals.
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
}