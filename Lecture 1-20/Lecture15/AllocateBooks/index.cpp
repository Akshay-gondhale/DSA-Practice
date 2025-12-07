// https://www.naukri.com/code360/problems/allocate-books_1090540?source=youtube&campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM&count=25&page=1&search=allocate%20&sort_entity=order&sort_order=ASC&customSource=studio_nav
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sumArr(vector<int> &arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
bool isPossibleSol(vector<int> &books, int size, int students, int mid)
{
    int sum = 0;
    int totalBlocks = 0;
    for (int i = 0; i < size; i++)
    {
        sum += books[i];
        if (sum > mid)
        {
            totalBlocks++;
            sum = books[i];
        }
    }
    cout << "FOR MID " << mid << " TOTALBLOCK ARE: " << totalBlocks << " ::: CONDITION: " << (totalBlocks < students) << endl;
    if (totalBlocks < students)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int distributeBooks(vector<int> &books, int size, int students, int arrSum)
{
    int start = 0;
    int end = arrSum;
    int ans = -1;
    // handling edge cases
    if (size == students)
    {
        vector<int> copyArr = books;
        sort(copyArr.begin(), copyArr.end());
        return copyArr[copyArr.size() - 1];
    }
    else if (size < students)
    {
        return -1;
    }
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        cout << start << "--" << mid << "--" << end << endl;
        if (isPossibleSol(books, size, students, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int noOfBooks;
    cout << "Enter number of books: ";
    cin >> noOfBooks;
    vector<int> books;
    cout << "Enter pages for each book: ";
    for (int i = 0; i < noOfBooks; i++)
    {
        int input;
        cin >> input;
        books.push_back(input);
    }
    int noOfStudents;
    cout << "Enter number of students: ";
    cin >> noOfStudents;
    // main start
    int sumOfArray = sumArr(books, noOfBooks);
    cout << distributeBooks(books, noOfBooks, noOfStudents, sumOfArray) << endl;
}