#include <bits/stdc++.h>
using namespace std;

class Human
{
public:
    int age;

    void speaking()
    {
        cout << "Speaking" << endl;
    }
};

/*
 *? Access Modifier Effect During Inheritance
 *
 *  Base Class Member     | public      | protected   | private
 *  ------------------------------------------------------------
 *  public member         | public      | protected   | private
 *  protected member      | protected   | protected   | private
 *  private member        | inaccessible| inaccessible| inaccessible
 *
 *? In this example, Human is inherited using public inheritance.
 *? Therefore, the public members of Human remain public members
 *? of Male and can be accessed using a Male object.
 *
 *? Here:
 *?  - age remains public in Male.
 *?  - speaking() remains public in Male.
 *?  - greet() is directly declared as public in Male.
 */
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
    Male akshay;

    //? greet() is directly declared as public inside Male.
    akshay.greet();

    //? speaking() is public in Human and remains public in Male
    //? because Human is inherited using public inheritance.
    akshay.speaking();
}