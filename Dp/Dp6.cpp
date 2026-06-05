#include <bits/stdc++.h>
using namespace std;

int KnapsackMandatoryHeavy(int weights[], int values[], int n, int capacity, int H) {
    int INF = -1e9;

    bool hasHeavy = false;
    for(int i=0;i<n;i++) if(weights[i] >= H) {
    hasHeavy = true;
     break;
     }
    if(!hasHeavy) return -1;

    int dp[n+1][capacity+1];

    for(int i=0;i<=n;i++)
        for(int w=0;w<=capacity;w++)
            dp[i][w] = 0;

    for(int i=1;i<=n;i++){
        for(int w=0;w<=capacity;w++){
            dp[i][w] = dp[i-1][w];
            if(w >= weights[i-1])
                dp[i][w] = max(dp[i][w], dp[i-1][w - weights[i-1]] + values[i-1]);
        }
    }

    int maxValue = -1;

    for(int i=0;i<n;i++){
        if(weights[i] >= H){
            int remainingCap = capacity - weights[i];
            if(remainingCap < 0) continue;

            int dp2[n+1][remainingCap+1];
            for(int x=0;x<=n;x++)
                for(int y=0;y<=remainingCap;y++)
                    dp2[x][y] = 0;

            for(int x=1;x<=n;x++){
                for(int y=0;y<=remainingCap;y++){
                    dp2[x][y] = dp2[x-1][y];
                    if(x-1 != i && y >= weights[x-1])
                        dp2[x][y] = max(dp2[x][y], dp2[x-1][y - weights[x-1]] + values[x-1]);
                }
            }

            int totalValue = values[i] + dp2[n][remainingCap];
            maxValue = max(maxValue, totalValue);
        }
    }

    return maxValue == -1 ? -1 : maxValue;
}

int main() {
    int n, capacity, H;
    cout << "Enter number of items, capacity and H (weight threshold for heavy item): ";
    cin >> n >> capacity >> H;

    int weights[n], values[n];
    cout << "Enter weights: ";
    for(int i=0;i<n;i++) cin >> weights[i];

    cout << "Enter values: ";
    for(int i=0;i<n;i++) cin >> values[i];

    int ans = KnapsackMandatoryHeavy(weights, values, n, capacity, H);
    cout << "Maximum value with at least one heavy item: " << ans << endl;

    return 0;
}
