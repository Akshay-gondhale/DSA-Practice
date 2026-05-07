#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
    simpleSieve(limit, prime)

    Purpose:
    --------
    Finds all prime numbers <= limit using normal Sieve of Eratosthenes.

    Why needed?
    -----------
    In segmented sieve, we only need primes up to sqrt(n),
    because every composite number has at least one factor <= sqrt(n).

    Output:
    -------
    - Stores primes in vector 'prime'
    - Also prints them
*/
void simpleSieve(int limit, vector<int> &prime)
{
    vector<bool> mark(limit + 1, true);

    // Standard sieve
    for (int p = 2; p * p < limit; p++)
    {
        if (mark[p])
        {
            for (int i = p * p; i < limit; i += p)
                mark[i] = false;
        }
    }

    // Store primes
    for (int p = 2; p < limit; p++)
    {
        if (mark[p])
        {
            prime.push_back(p);
            cout << p << " ";
        }
    }
}

/*
    segmentedSieve(n)

    Purpose:
    --------
    Prints all prime numbers < n using segmented sieve.

    Idea:
    -----
    1. Compute primes up to sqrt(n)
    2. Divide remaining range into segments of size ~ sqrt(n)
    3. Use precomputed primes to mark composites in each segment

    Advantage:
    ----------
    Uses less memory than normal sieve for large n
*/
void segmentedSieve(int n)
{
    // Step 1: Compute primes up to sqrt(n)
    int limit = floor(sqrt(n)) + 1;

    vector<int> prime;
    prime.reserve(limit);

    simpleSieve(limit, prime);

    // Step 2: Define first segment
    int low = limit;
    int high = 2 * limit;

    // Process all segments
    while (low < n)
    {
        if (high > n)
            high = n;

        /*
            mark[i] represents number (i + low)

            Example:
            If low = 50:
                mark[0] -> 50
                mark[1] -> 51
                ...
        */
        vector<bool> mark(high - low, true);

        // Step 3: Mark multiples using known primes
        for (int p : prime)
        {
            /*
                Find FIRST multiple of p inside [low, high)

                Logic:
                floor(low / p) * p gives largest multiple <= low
                If it's < low, move to next multiple by adding p
            */
            int loLim = (low / p) * p;

            if (loLim < low)
                loLim += p;

            /*
                Alternative (cleaner):
                int loLim = ((low + p - 1) / p) * p;
            */

            // Mark all multiples of p in this segment
            for (int j = loLim; j < high; j += p)
            {
                /*
                    Mapping:
                    number j → index (j - low)

                    Example:
                    low = 50
                    j = 53 → mark[3]
                */
                mark[j - low] = false;
            }
        }

        // Step 4: Print primes in current segment
        for (int i = low; i < high; i++)
        {
            if (mark[i - low])
                cout << i << " ";
        }

        // Step 5: Move to next segment
        low += limit;
        high += limit;
    }
}

int main()
{
    int n = 100;
    cout << "Primes smaller than " << n << ":\n";

    segmentedSieve(n);

    return 0;
}