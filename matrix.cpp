#include <iostream>
#include <climits>

using namespace std;

// Function to find the minimum number of multiplications needed to multiply the chain of matrices
int matrixChainMultiplication(int p[], int n) {
    // Create a 2D table to store the minimum number of multiplications
    int m[n][n];

    // m[i][i] is zero because we need zero multiplications to multiply one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is the chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            // Try every possible split to find the minimum cost
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    // The minimum cost is found at m[1][n-1]
    return m[1][n - 1];
}

int main() {
    // The dimensions of the matrices are given in an array p such that
    // the dimension of matrix A is p[0] x p[1]
    // the dimension of matrix B is p[1] x p[2]
    // the dimension of matrix C is p[2] x p[3]
    // the dimension of matrix D is p[3] x p[4]
    int p[] = {2, 3, 4, 5, 2};
    int n = sizeof(p) / sizeof(p[0]);

    cout << "Minimum number of multiplications is " << matrixChainMultiplication(p, n) << endl;

    return 0;
}

