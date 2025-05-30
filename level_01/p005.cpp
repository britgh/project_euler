/*  P005: Smallest Multiple

    2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
    What is the smallest positive number that is evenly divisible (no remainders) by all of the numbers from 1 to 20? */

#include <iostream>
using namespace std;

struct node {
    int num;
    node * next;
    node * back;
};

void insert (node * dummy, int num) {
    node * newnode = new node;
    newnode -> num = num;

    if (dummy -> next == dummy) {           // list is empty
        dummy -> back = newnode;
        dummy -> next = newnode;

        newnode -> back = dummy;
        newnode -> next = dummy;
    } else {
        newnode -> back = dummy -> back;    // newnode back is last element
        dummy -> back -> next = newnode;    // last element points to new

        newnode -> next = dummy;            // new element is last
        dummy -> back = newnode;            // dummy back is newnode
    } 
}

void remove (node * current) {
    if (current -> back != current -> next) {
        node * previous = current -> back;

        previous -> next = current -> next;
        previous -> next -> back = previous;

        delete current;
    } else {
        cout << "ERROR: list is empty" << endl;
    }
}

void printList (node * dummy) {
    long long val = 1;

    // traverse doubly LL    
    for (node * current = dummy -> next; current != dummy; current = current -> next) {
        cout << current -> num << ' ';
        val *= current -> num;
    }

    cout << "value: " << val << endl;
}

// check if node being inserted is already in list, else insert
bool original (node * dummy, int num) {
    for (node * current = dummy -> next; current != dummy; current = current -> next) {
        if (current -> num == num) {
            // cout << current -> num << " already in list" << endl;
            return false;
        }
    }
    insert(dummy, num);
    return true;
}

int main () {
    node * dummy = new node;    // doubly LL
    dummy -> next = dummy;
    dummy -> back = dummy;

    // inserting 20 and numbers that are not factors
    insert (dummy, 20);

    for (int i = 1; i < 20; i++) {
        if (20 % i != 0) {
            insert (dummy, i);
        }
    }

    node * current = dummy -> back;     // largest non-factor

    // traverse list backwards of current
    while (current != dummy) {
        for (node * factor = current -> back; factor != dummy; factor = factor -> back) {
            if (current -> num % factor -> num == 0) {
                node * factor2 = factor;
                factor = factor -> back;
                remove (factor2);
            }
        } 
        current = current -> back;
    }
    printList(dummy);   // list of all vals not divisible by another in list...

    return 0;
}