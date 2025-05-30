/*  P007: 10 001st Prime

    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that
    the 6th prime is 13.
    What is the 10,001st prime number? */

#include <iostream>
using namespace std;

int const LIMIT = 10001;
int arr[LIMIT];
int last = 1;

bool prime (int num);

int main () {
    arr[0] = 2;

    for (int i = 3; i < 1000000; i += 2) {
        if (prime(i)) {
            arr[last] = i;
            last++;
            cout << "place: " << last << " num: " << i << endl;
        }
        if (last >= LIMIT) {
            break;
        }
    }
    return 0;
}

bool prime (int num) {
    for (int i = 0; i < last; i++) {    // cannot be equal to last
        if (num % arr[i] == 0) {
            return false;
        }
    }
    return true;
}