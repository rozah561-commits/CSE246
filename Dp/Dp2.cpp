#include <bits/stdc++.h>
using namespace std;

long long Coin_Change_AtMostK(int coins[], int n, int amount, int K) {
    long long dp[n+1][amount+1][K+1];

    for(int i=0;i<=n;i++)
        for(int j=0;j<=amount;j++)
            for(int k=0;k<=K;k++)
                dp[i][j][k] = 0;

    for(int i=0;i<=n;i++)
        dp[i][0][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=amount;j++){
            for(int k=0;k<=K;k++){
                dp[i][j][k] = dp[i-1][j][k];

                if(j >= coins[i-1] && k >= 1)
                    dp[i][j][k] += dp[i][j - coins[i-1]][k-1];
            }
        }
    }

    long long total = 0;
    for(int k=0;k<=K;k++)
        total += dp[n][amount][k];

    return total;
}

int main() {
    int n, amount, K;
    cin >> n >> amount >> K;
    int coins[n];
    for(int i=0;i<n;i++) cin >> coins[i];

    cout << Coin_Change_AtMostK(coins, n, amount, K) << endl;
    return 0;
}
