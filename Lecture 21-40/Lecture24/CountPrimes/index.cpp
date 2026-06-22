// -----------------------------------------------------------------------------
// Learning focus: Count Primes
// Purpose: Counts primes using Count Primes.
// Core idea: Sieve methods mark multiples of each discovered prime so composite numbers are skipped efficiently.
// Complexity note: The standard sieve runs in O(n log log n) time and O(n) space; segmented variants reduce the active range memory.
// Read the inline code and comments below to connect this idea to each step.
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/count-primes/submissions/1988670480/
#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<bool> &numArr)
{
    for (int i = 0; i < numArr.size(); i++)
    {
        cout << numArr[i] << ' ';
    }
    cout << endl;
}
int countPrimes(int n)
{
    if (n == 0)
        return 0;
    vector<bool> primeCount(n, true);
    primeCount[0] = primeCount[1] = false;
    cout << "<=================== BEFORE ==================>" << endl;
    printVector(primeCount);
    cout << "<=================== BEFORE ==================>" << endl;
    int foundPrimes = 0;
    for (int i = 2; i < primeCount.size(); i++)
    {
        if (primeCount[i])
        {
            foundPrimes++;
            // marking all other numbers which found in current i's table
            for (int j = 2 * i; j < primeCount.size(); j = j + i)
            {
                if (j % i == 0)
                {
                    primeCount[j] = false;
                }
            }
        }
    }

    cout << "<=================== AFTER ==================>" << endl;
    printVector(primeCount);
    cout << "<=================== AFTER ==================>" << endl;
    return foundPrimes;
}
int main()
{
    int num;
    cout << "Enter number to count primes from 2: " << endl;
    cin >> num;
    int result = countPrimes(num);
    cout << "There are total " << result << " prime number in between 0 to " << num << endl;
}