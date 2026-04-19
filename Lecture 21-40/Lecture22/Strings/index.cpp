#include <iostream>
using namespace std;
int getLength(char *name)
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char name[20];
    cout << "Enter your name: ";
    cin >> name;
    cout << "Your name is: " << name << endl;

    // \0 -> This is called as null character. In and char array null character is added after the last character of string.
    // cout will print upto \0 only.

    // adding \0 intentionally to check behavior
    // name[3] = '\0';
    // cout << "Your name after adding '\\0' is: " << name << endl;

    int lenOfName = getLength(name);
    cout << "Length of string is: " << lenOfName << endl;
}