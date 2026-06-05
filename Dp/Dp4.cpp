#include <bits/stdc++.h>
using namespace std;

int MinCoinsUsageLimit(int coins[], int n, int amount){
    int INF = 1e9;
    int expanded[2*n];
    int m = 0;
    for(int i=0;i<n;i++){
        expanded[m++] = coins[i];
        expanded[m++] = coins[i];
    }

    int dp[m+1][amount+1];
    for(int i=0;i<=m;i++)
        for(int j=0;j<=amount;j++)
            dp[i][j] = INF;

    for(int i=0;i<=m;i++) dp[i][0] = 0;

    for(int i=1;i<=m;i++){
        for(int j=0;j<=amount;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= expanded[i-1] && dp[i-1][j - expanded[i-1]] != INF)
                dp[i][j] = min(dp[i][j], dp[i-1][j - expanded[i-1]] + 1);
        }
    }
    if(dp[m][amount] == INF) return -1;
    return dp[m][amount];
}

int main(){
    int n, amount;
    cout << "Enter number of coins and target amount: ";
    cin >> n >> amount;

    int coins[n];
    cout << "Enter coin values: ";
    for(int i=0;i<n;i++) cin >> coins[i];

    int ans = MinCoinsUsageLimit(coins, n, amount);
    cout << "Minimum coins needed (or -1 if impossible): " << ans << endl;

    return 0;
}
