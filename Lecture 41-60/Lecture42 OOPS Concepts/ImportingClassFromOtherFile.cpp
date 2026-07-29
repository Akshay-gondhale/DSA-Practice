#include <bits/stdc++.h>

//* Includes the definition of the Hero class.
//! In production code, include the corresponding header file (e.g., "Hero.h")
//! instead of a .cpp file to avoid multiple definition and compilation issues.
#include "Hero.cpp"

using namespace std;

/**
 * @brief Demonstrates creating an object of the Hero class and determining
 *        its memory footprint.
 *
 * Creates an instance of the Hero class and prints its size using the
 * sizeof operator. The reported size depends on the data members and any
 * compiler-added padding for alignment.
 *
 * @return int Returns 0 to indicate successful program execution.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
int main()
{
    //* Create an object of the Hero class.
    Hero suresh;

    //* Display the total memory occupied by the Hero object.
    cout << "Size of suresh: " << sizeof(suresh) << endl;

    return 0;
}