#include<bits/stdc++.h>
using namespace std;

// 🔷 Normal LCS function
int LCS(string X, string Y){
    int n = X.size();
    int m = Y.size();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

// 🔷 Main function
int main(){

    string X, Y;
    char C;

    cin >> X >> Y >> C;

    int n = X.size();
    int m = Y.size();

    int ans = 0;

    // 🔥 try all positions where C matches in both strings
    for(int i=0;i<n;i++){
        if(X[i] != C) continue;

        for(int j=0;j<m;j++){
            if(Y[j] != C) continue;

            // left part LCS
            int left = LCS(X.substr(0,i), Y.substr(0,j));

            // right part LCS
            int right = LCS(X.substr(i+1), Y.substr(j+1));

            // total = left + 1(C) + right
            ans = max(ans, left + 1 + right);
        }
    }

    cout << ans << endl;

    return 0;
}
