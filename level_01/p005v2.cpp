/*  P005: Smallest Multiple

    2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
    What is the smallest positive number that is evenly divisible (no remainders) by all of the numbers from 1 to 20? */

#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, int> count;      // stores factors + count

// check if prime
bool prime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void factorize (int num) {
    int arr[20] = {0};

    // store arr[factor] = factorCount
    for (int i = 2; i <= num; i++) {
        if (prime(i) && num % i == 0) {
            arr[i] += 1;
            num = num / i;
            i--;                    // check same prime again
        }
    }
    
    // update hashmap w/ greater factorCnts
    for (int i = 0; i < 20; i++) {
        if (arr[i] != 0 && count[i] < arr[i]) {
            count[i] = arr[i];
        }
    }
}

int main() {
    long long val = 1;

    // factorize values + insert count into hashmap (if greater than current count)
    for (int i = 2; i < 20; i++) {
        factorize(i);
    }

    // mutiplying all factors (val *= factor ^ factorCnt)
    for (auto it = count.begin(); it != count.end(); ++it) {
        cout << "num: " << it -> first << ", count: " << it -> second << endl;
        val *= pow(it -> first, it -> second);
    }
    cout << "val: " << val << endl;

    return 0;
}