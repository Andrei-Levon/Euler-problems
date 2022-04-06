#include <iostream>
#include <algorithm>
using namespace std;

/*The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330,
is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
There is one other 4-digit increasing sequence exhibiting this property.
What 12-digit number do you form by concatenating the three terms in this sequence? */

const int TEN = 10;
int ar[20], ar2[20];

bool prime(int a) {
    if (a > 9999) {
        return false;
    }
    for (int i = 2; i < a; ++i) {
        if (a % i == 0) {
            return false;
        } else if (i * i > a) {
            return true;
        }
    }
}

bool permutation(int a, int b, int ar[]) {
    int counter = 3;
    while (a > 0) {
        ar[counter] = a % TEN;
        ar2[counter] = b % TEN;
        a /= TEN;
        b /= TEN;
        --counter;
    }
    while (next_permutation(ar, ar + 4)) {
        if (ar[0] == ar2[0] && ar[1] == ar2[1] && ar[2] == ar2[2] && ar[3] == ar2[3]) {
            return true;
        }
        else if (ar[0] > ar2[0]) {
            break;
        }
    }
    return false;
}

int main() {
    int primes[2000], i = 0, aux = 0;
    for (int j = 0; j < 2000; ++j) {
        primes[j] = 0;
    }
    for (int j = 1001; j < 10000; ++j) {
        if (prime(j)) {
            primes[i] = j;
            ++i;
        }
    }
    for (int j = 0; j < 2000; ++j) {
        if (primes[j] == 1487) {
            continue;
        }
        for (int k = j + 1; k < 2000; ++k) {
            if (permutation(primes[j], primes[k], ar) && prime(primes[k] * 2 - primes[j])) {
                if (permutation(primes[k], primes[k] * 2 - primes[j], ar)) {
                    cout << primes[j] << primes[k] << primes[k] * 2 - primes[j];
                    aux = 1;
                    break;
                }
            }
        }
        if (aux == 1) {
            break;
        }
    }
    return 0;
}
