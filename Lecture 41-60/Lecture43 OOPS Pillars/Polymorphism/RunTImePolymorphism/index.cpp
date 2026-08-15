#include <bits/stdc++.h>
using namespace std;

//*  Runtime polymorphism allows a base class pointer/reference to invoke
//*  the overridden function of the actual derived object at runtime.
//?  The virtual keyword enables dynamic binding for speak().
class Animal
{
public:
    /**
     * @brief Displays the generic speaking behavior of an animal.
     *
     * Declared as virtual so that derived classes can override this
     * function and the appropriate implementation can be selected
     * at runtime through a base class pointer or reference.
     *
     * @note The virtual keyword enables runtime polymorphism.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    virtual void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    /**
     * @brief Overrides Animal::speak() with Dog-specific behavior.
     *
     * This is function overriding because Dog provides its own
     * implementation of the virtual speak() function inherited from Animal.
     *
     * @note When called through an Animal pointer or reference, the Dog
     * implementation is selected at runtime because speak() is virtual.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void speak()
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    Dog sheru;

    //? Directly calling speak() on a Dog object selects Dog::speak().
    sheru.speak();

    //? The pointer is of type Animal*, but the actual object is Dog.
    //? Because speak() is virtual, runtime polymorphism causes
    //? Dog::speak() to be called instead of Animal::speak().
    Animal *moti = new Dog();
    moti->speak();
}