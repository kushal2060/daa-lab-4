#include <iostream>

using namespace std;

// Function to compute gcd of a and b
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute modular multiplicative inverse of a under modulo m
int modInverse(int a, int m) {
    int m0 = m, x0 = 0, x1 = 1;
    if (m == 1) return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;

    return x1;
}

// Function to solve the system of congruences using the Chinese Remainder Theorem
int chineseRemainderTheorem(int a[], int m[], int n) {
    int M = 1;
    for (int i = 0; i < n; i++) M *= m[i];

    int x = 0;
    for (int i = 0; i < n; i++) {
        int Mi = M / m[i];
        int yi = modInverse(Mi, m[i]);
        x = (x + a[i] * Mi * yi) % M;
    }

    return x < 0 ? x + M : x;
}

int main() {
    int a[] = {2, 3, 2}; // remainders
    int m[] = {3, 5, 7}; // moduli
    int n = sizeof(a) / sizeof(a[0]);

    int result = chineseRemainderTheorem(a, m, n);
    cout << "The solution is " << result << endl;

    return 0;
}

