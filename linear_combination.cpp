#include <iostream>
using namespace std;

int extendedGCD(int a, int b, int &x, int &y) {
    int x0 = 1, x1 = 0, y0 = 0, y1 = 1;
    int q, temp;

    while (b != 0) {
        q = a / b;
        temp = a % b;
        a = b;
        b = temp;

        temp = x1;
        x1 = x0 - q * x1;
        x0 = temp;

        temp = y1;
        y1 = y0 - q * y1;
        y0 = temp;
    }

    x = x0;
    y = y0;
    return a;
}

int main() {
    int a = 48, b = 18;
    int x, y;
    int gcd = extendedGCD(a, b, x, y);
    cout << "GCD: " << gcd << endl;
    cout << "Coefficients: x = " << x << ", y = " << y << endl;
    cout << "Linear combination: " << a << "*" << x << " + " << b << "*" << y << " = " << gcd << endl;
    return 0;
}

