#include <iostream>
using namespace std;
bool linearSearch(int arr[], int size, int keyToSearch)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == keyToSearch)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int numArr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> numArr[i];
    }
    int keyToSearch;
    cout << "Enter key to search: ";
    cin >> keyToSearch;

    bool result = linearSearch(numArr, size, keyToSearch);
    if (result)
    {
        cout << keyToSearch << " found in array." << endl;
    }
    else
    {
        cout << keyToSearch << " not found in array." << endl;
    }
}