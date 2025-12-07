// maps are basically dictionary and object.
// in cpp there are two types of map --> ordered map and unordered map.
// int this we will see ordered map
#include <iostream>
#include <map>
using namespace std;
void printingMap(map<int, string> inputMap)
{
    for (auto i : inputMap)
    {
        cout << i.first << " :: " << i.second << endl;
    }
}
int main()
{
    // init ordered map
    map<int, string> friends;
    // inserting key values in random ordered but it will sort it while storing
    // it uses internally random black tree or balance tree techniques to store values in ordered
    // unordered map uses hash tables so thats why its complexity to find will be O(1)
    friends[1] = "Akshay";
    friends[3] = "Rohit";
    friends[2] = "Praneet";
    printingMap(friends);
    cout << endl;
    // checking if any key is present in map using .count()
    cout << "Is 3 present? = " << friends.count(3) << endl;
    cout << "Is 4 present? = " << friends.count(4) << endl;
    cout << endl;

    // removing an element using erase method and passing key to it
    friends.erase(3);
    cout << "Post erase:" << endl;
    printingMap(friends);
    cout << endl;

    // inserting few more elements with an different approach like .insert({})
    friends.insert({3, "Rohit"});
    friends.insert({4, "Rakesh"});
    friends.insert({5, "Shushmit"});
    cout << "Post inserting new friends: " << endl;
    printingMap(friends);
    cout << endl;

    // .find() method
    // it returns an iterator
    auto it = friends.find(3);
    cout << "Post finding iterator: " << endl;
    for (auto i = it; i != friends.end(); i++)
    {
        cout << (*i).first << " :: " << (*i).second << endl;
    }
}