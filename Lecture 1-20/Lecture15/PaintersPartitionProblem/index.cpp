// https://www.naukri.com/code360/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2
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
bool isPossibleSol(vector<int> &paintBoards, int size, int painters, int mid)
{
    int sum = 0;
    int totalPaintBoards = 0;
    for (int i = 0; i < size; i++)
    {
        sum += paintBoards[i];
        if (sum > mid)
        {
            totalPaintBoards++;
            sum = paintBoards[i];
            if (sum > mid)
            {
                // if any single element is bigger than mid then directly return false as no painter should get more than mid; everyone should get mid or less than mid
                return false;
            }
        }
    }

    if (totalPaintBoards < painters)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int distributePaintBoards(vector<int> &paintBoards, int size, int painters, int arrSum)
{
    int start = 0;
    int end = arrSum;
    int ans = -1;
    // handling edge cases
    if (size == painters)
    {
        vector<int> copyArr = paintBoards;
        sort(copyArr.begin(), copyArr.end());
        return copyArr[copyArr.size() - 1];
    }
    else if (size < painters)
    {
        return -1;
    }

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        cout << "START: " << start << " MID: " << mid << " END: " << end << " IS POSSIBLE SOL: " << isPossibleSol(paintBoards, size, painters, mid) << endl;
        if (isPossibleSol(paintBoards, size, painters, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << ans << endl;
    return -1;
}
int main()
{
    int noOfPaintBoards;
    cout << "Enter number of paint boards: ";
    cin >> noOfPaintBoards;
    vector<int> paintBoards;
    cout << "Enter pages for each book: ";
    for (int i = 0; i < noOfPaintBoards; i++)
    {
        int input;
        cin >> input;
        paintBoards.push_back(input);
    }
    int noOfPainters;
    cout << "Enter number of painters: ";
    cin >> noOfPainters;
    // main start
    int sumOfArray = sumArr(paintBoards, noOfPaintBoards);
    distributePaintBoards(paintBoards, noOfPaintBoards, noOfPainters, sumOfArray);
}