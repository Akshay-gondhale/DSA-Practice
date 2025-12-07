// set always stores unique elements event if you insert duplicated values it will ignore duplicates and it will only store unique once.
#include <iostream>
#include <set>
using namespace std;
void printingSet(set<int> nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    // init
    set<int> nums;
    // inserting duplicated values
    nums.insert(1);
    nums.insert(2);
    nums.insert(3);
    nums.insert(2);
    nums.insert(1);
    nums.insert(1);
    nums.insert(5);
    cout << "Init set: " << endl;
    printingSet(nums);
    cout << endl;
    nums.erase(nums.begin());
    cout << "Post first element delition: " << endl;
    printingSet(nums);
    cout << endl;

    // .count() method
    // this checks if element is present in set or not.
    cout << "Is 10 present in the state? : " << nums.count(10) << endl;
    cout << "Is 5 present in the state? : " << nums.count(5) << endl;
    cout << endl;
    // .find() method
    // this give iterator of the element present.
    // eg: if we find 3 currently 3 is on 1st index. so when you take iterator and print current and next element it will print elements present after 3
    cout << "Elements after finding 3: " << endl;
    set<int>::iterator itr = nums.find(3);
    for (auto it = itr; it != nums.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
