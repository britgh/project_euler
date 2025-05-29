/* P004: Largest Palindrome Product

    A palindromic number reads the same both ways. 
    The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.
    Find the largest palindrome made from the product of two 3-digit numbers. */

#include <iostream>
#include <string>
using namespace std;

bool palindrome (int num);

int main () {
    const int MAX = 999 * 999;
    int num;
    int pal = 0;

    for (int i = 1; i <= 999; i++) {
        for (int j = 1; j <= 999; j++) {
            num = i * j;
            if (palindrome(num) && (num > pal)) {
                cout << "i: " << i << " j: " << j << '\n';
                pal = num;
            }
        }
    }
    cout << " pal: " << pal;

    return 0;
}

bool palindrome (int num) {
    string val = to_string(num);

    for (int i = 1; i <= val.length()/2; i++) {     // compare 1st + last 'num' chars
        if (val[i-1] != val[val.length()-i]) {
            // cout << val[i-1] << ' ' << val[val.length()-i] << ' ';
            return false;
        }
    }
    return true;
}