#include <bits/stdc++.h>
using namespace std;

int MinCoinsMandatory(int coins[], int n, int amount, int C) {
    int INF = 1e9;

    if(C > amount) return -1;

    int remaining = amount - C;

    int dp[n+1][remaining+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=remaining;j++)
            dp[i][j] = INF;

    for(int i=0;i<=n;i++)
        dp[i][0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=remaining;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= coins[i-1] && dp[i][j - coins[i-1]] != INF)
                dp[i][j] = min(dp[i][j], dp[i][j - coins[i-1]] + 1);
        }
    }

    if(dp[n][remaining] == INF) return -1;

    return dp[n][remaining] + 1;
}

int main() {
    int n, amount, C;
    cout << "Enter number of coins and target amount: ";
    cin >> n >> amount;

    cout << "Enter mandatory coin value: ";
    cin >> C;

    int coins[n];
    cout << "Enter the coin values: ";
    for(int i=0;i<n;i++)
        cin >> coins[i];



    int ans = MinCoinsMandatory(coins, n, amount, C);
    cout << "Minimum coins needed (or -1 if impossible): " << ans << endl;

    return 0;
}
