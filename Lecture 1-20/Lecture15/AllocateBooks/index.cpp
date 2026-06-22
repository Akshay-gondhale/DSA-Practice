// -----------------------------------------------------------------------------
// Learning focus: Allocate Books
// Purpose: Solves Allocate Books with binary search on the answer.
// Core idea: A feasibility check greedily tests a candidate limit; binary search then finds the smallest valid limit.
// Complexity note: For n items and search range S, time is O(n log S) and extra space is O(1).
// -----------------------------------------------------------------------------
// https://www.naukri.com/code360/problems/allocate-books_1090540?source=youtube&campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM&count=25&page=1&search=allocate%20&sort_entity=order&sort_order=ASC&customSource=studio_nav
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Returns the sum of the supplied elements.
int sumArr(vector<int> &arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
// Greedily tests whether a proposed maximum workload can satisfy the allocation constraints.
bool isPossibleSol(vector<int> &books, int size, int students, int mid)
{
    int sum = 0;
    int totalBlocks = 0;
    // Key idea: Start a new student/painter when the current allocation would exceed the candidate limit.
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

// Uses binary search on the maximum allowed workload to find the smallest feasible answer.
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
        // Choose the middle index with an overflow-safe formula before deciding which half remains relevant.
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
