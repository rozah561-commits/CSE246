
#include <bits/stdc++.h>
using namespace std;

int main() {
    string X, Y;
    cin >> X >> Y;

    int n = X.size();
    int m = Y.size();

    int dp[n+1][m+1];
    char b[n+1][m+1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {

            if(i == 0 || j == 0) {
                dp[i][j] = 0;
                b[i][j] = '0';
            }

            else if(X[i-1] == Y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                b[i][j] = 'D';
            }

            else if(dp[i-1][j] >= dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                b[i][j] = 'U';
            }

            else {
                dp[i][j] = dp[i][j-1];
                b[i][j] = 'L';
            }
        }
    }

    // Backtracking to get LCS string
    string lcs = "";
    int i = n, j = m;

    while(i > 0 && j > 0) {
        if(b[i][j] == 'D') {
            lcs += X[i-1];
            i--;
            j--;
        }
        else if(b[i][j] == 'U') {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << "LCS length: " << dp[n][m] << endl;
    cout << "LCS: " << lcs << endl;

    return 0;
}
