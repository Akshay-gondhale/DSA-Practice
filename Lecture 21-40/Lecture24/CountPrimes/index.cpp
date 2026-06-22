// -----------------------------------------------------------------------------
// Learning focus: Count Primes
// Counts how many prime numbers are strictly smaller than n using the
// Sieve of Eratosthenes.
// Time complexity: O(n log log n) | Space complexity: O(n)
// -----------------------------------------------------------------------------
// https://leetcode.com/problems/count-primes/submissions/1988670480/
#include <iostream>
#include <vector>
using namespace std;

// Prints the sieve's boolean flags so its state can be inspected before and
// after composite numbers are marked. This is only a debugging/learning helper.
void printVector(vector<bool> &numArr)
{
    for (int i = 0; i < numArr.size(); i++)
    {
        cout << numArr[i] << ' ';
    }
    cout << endl;
}

// Builds a sieve for the range [0, n). A true flag means that the number is
// still considered prime; false means it is known to be non-prime.
int countPrimes(int n)
{
    // The current implementation assumes n is either 0 or at least 2.
    // For n == 1, primeCount[1] below would be outside the vector.
    if (n == 0)
        return 0;

    // Initially treat every number as a possible prime.
    vector<bool> primeCount(n, true);

    // Zero and one are not prime, so exclude them before running the sieve.
    primeCount[0] = primeCount[1] = false;

    // Show the initial candidate flags before any multiples are eliminated.
    cout << "<=================== BEFORE ==================>" << endl;
    printVector(primeCount);
    cout << "<=================== BEFORE ==================>" << endl;

    int foundPrimes = 0;

    // If i is still marked true, no smaller prime divided it; therefore i is
    // prime. Count it and eliminate all of its remaining multiples.
    for (int i = 2; i < primeCount.size(); i++)
    {
        if (primeCount[i])
        {
            foundPrimes++;

            // Every value generated here is a multiple of i and therefore
            // composite. Starting at 2*i avoids marking i itself.
            for (int j = 2 * i; j < primeCount.size(); j = j + i)
            {
                // This condition is always true because j starts at 2*i and
                // increases by i. It is retained to match the original logic.
                if (j % i == 0)
                {
                    primeCount[j] = false;
                }
            }
        }
    }

    // Show which values remain marked as prime after the sieve completes.
    cout << "<=================== AFTER ==================>" << endl;
    printVector(primeCount);
    cout << "<=================== AFTER ==================>" << endl;

    return foundPrimes;
}

// Reads the exclusive upper bound, runs the sieve, and displays its count.
int main()
{
    int num;
    cout << "Enter number to count primes from 2: " << endl;
    cin >> num;
    int result = countPrimes(num);
    cout << "There are total " << result << " prime number in between 0 to " << num << endl;
}
