#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void bubbleSort(int coins[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(coins[j] > coins[j + 1]){
                swap(coins[j], coins[j + 1]);
            }
        }
    }
}
void coinChange(int coins[], int n, int target){

    int dp[n+1][target+1];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for(int j = 1; j <= target; j++){
        dp[0][j] = INF;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++){

            if(coins[i-1] <= j){

                int take = 1 + dp[i][j - coins[i-1]];
                int notTake = dp[i-1][j];

                dp[i][j] = min(take, notTake);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[n][target] >= INF){
        cout << "No solution\n";
        return;
    }
    cout << "Minimum coins: " << dp[n][target] << endl;
    int count[n] = {0};
    int i = n, j = target;
    while(j > 0 && i > 0){

        if(dp[i][j] == dp[i-1][j]){
            i--; // skip coin
        }
        else{
            count[i-1]++; // take coin
            j = j - coins[i-1];
        }
    }
    cout << "\nCoin usage:\n";
    for(int k = 0; k < n; k++){
        if(count[k] > 0){
            cout << coins[k] << " " << count[k] << endl;
        }
    }
}
int main(){
    int n, target;
    cout << "Enter number of coins: ";
    cin >> n;
    cout << "Enter target amount: ";
    cin >> target;
    int coins[n];
    cout << "Enter coin values: ";
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    bubbleSort(coins, n);
    coinChange(coins, n, target);
    return 0;
}
