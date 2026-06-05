
#include <bits/stdc++.h>
using namespace std;

int KnapsackExactlyK(int weights[], int values[], int n, int capacity, int K) {
    int INF = -1e9;

    int dp[n+1][capacity+1][K+1];

    for(int i=0;i<=n;i++)
        for(int w=0;w<=capacity;w++)
            for(int k=0;k<=K;k++)
                dp[i][w][k] = INF;

    for(int i=0;i<=n;i++)
        for(int w=0;w<=capacity;w++)
            dp[i][w][0] = 0;

    for(int i=1;i<=n;i++){
        for(int w=0;w<=capacity;w++){
            for(int k=0;k<=K;k++){

                dp[i][w][k] = dp[i-1][w][k];

                if(k >= 1 && w >= weights[i-1] && dp[i-1][w - weights[i-1]][k-1] != INF)
                    dp[i][w][k] = max(dp[i][w][k], dp[i-1][w - weights[i-1]][k-1] + values[i-1]);
            }
        }
    }

    if(dp[n][capacity][K] == INF) return -1;
    return dp[n][capacity][K];
}

int main() {
    int n, capacity, K;
    cout << "Enter number of items, capacity and K: ";
    cin >> n >> capacity >> K;

    int weights[n], values[n];
    cout << "Enter weights: ";
    for(int i=0;i<n;i++) cin >> weights[i];

    cout << "Enter values: ";
    for(int i=0;i<n;i++) cin >> values[i];

    int ans = KnapsackExactlyK(weights, values, n, capacity, K);
    cout << "Maximum value with exactly K items: " << ans << endl;

    return 0;
}
