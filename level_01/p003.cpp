/*  P003: Largest Prime Factor

    The prime factors of 13195 are 5, 7, 13, and 29.
    What is the largest prime factor of the number 600851475143? */

#include <iostream>
#include <cmath>
using namespace std;

bool prime (int num);

main () {
    long long value = 600851475143;
    int factor;

    for (int i = 2; i < sqrt(value); i++) {
        if (600851475143 % i == 0 && prime(i)) {      // is a factor, factor is prime
            factor = i;
            cout << factor << ' ';
        }
    }
    cout << "Largest Prime Factor: " << factor << endl;
    
    return 0;
}

bool prime (int num) {
    for (int i = 2; i < sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}