/*  P001: Multiples of 3 or 5

    If we list all the natural numbers below 10 that are multiples
    of 3 or 5, we get 3, 5, 6, or 9. The sum of these multiples is 23.
    Find the sum of all the multiples of 3 or 5 below 1000. */

#include <iostream>
using namespace std;

int main() {
    int value = 1000;
    int sum = 0;

    for (int i = 1; i < value; i++) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            sum += i;
        }
    }
    cout << sum << endl;
}