/*  P006: Sum Square Difference

    The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... + 10^2 = 385.
    The square of the sum of the first ten natural numbers is,(1 + 2 + ... + 10)^2 = 55^2 = 3025.
    Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
    Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum. */

#include <iostream>
using namespace std;

int main () {
    long long sum_squares = 0;
    long long sum = 0;

    for (int i = 1; i <= 100; i++) {
        sum_squares += i * i;
        sum += i;
        cout << "sum_squares: " << sum_squares << " sum: " << sum << endl;
    }

    sum *= sum;
    sum -= sum_squares;
    cout << "sum: " << sum << endl;

    return 0;
}