/*  P010: Summation of Primes

    The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
    Find the sum of all the primes below two million.
*/

#include <iostream>
#include <cmath>
using namespace std;

bool prime (int num);
int arr[150000];   // array of primes
int last = 0;      // first empty index of arr

int main () {
    int limit = 2000000;
    long long sum = 0;

    for (int i = 2; i < limit; i++) {   // all vals under 1mil
        if (prime(i)) {
            arr[last] = i;
            last++;

            sum += i;
            cout << i << ' ';
        }
    }
    cout << "count: " << last << " sum: " << sum << endl;

    return 0;
}

bool prime (int num) {
    for (int i = 0; i < last; i++) {    // prime arr indices
        if (num % arr[i] == 0) {        // if divisible by previous prime, not prime; later check if faster w/: &&  arr[i] <= sqrt(num) 
            return false;
        }
    }
    return true;
}