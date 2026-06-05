
#include <bits/stdc++.h>
using namespace std;

// Count ways to make target using unlimited supply of coins
int countWays(int coins[], int n, int target)
{
    int dp[21][501]; // n <= 20, target <= 500

    // Initialize dp array
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= target; j++)
            dp[i][j] = 0;

    // Base case: amount 0 can always be made with 0 coins
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Fill DP table
    for(int i = 1; i <= n; i++) // consider first i coins
    {
        for(int j = 1; j <= target; j++) // amount from 1 to target
        {
            if(coins[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]; // take or skip
            else
                dp[i][j] = dp[i-1][j]; // cannot take coin i
        }
    }

    return dp[n][target];
}

int main()
{
    int n, target;
    cin >> n >> target;

    int coins[20];
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    cout << countWays(coins, n, target) << endl;

    return 0;
}
