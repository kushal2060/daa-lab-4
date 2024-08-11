#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int min(int x, int y, int z) {
    return std::min(std::min(x, y), z);
}

int editDistance(string x, string y) {
    int m = x.length();
    int n = y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string x = "EXECUTION";
    string y = "INTENTION";
    cout << "The minimum edit distance between " << x << " and " << y << " is " << editDistance(x, y) << endl;
    return 0;
}
