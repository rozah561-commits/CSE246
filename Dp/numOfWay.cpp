#include <bits/stdc++.h>
using namespace std;

int countWays(int coins[], int n, int target, int K)
{
    int dp[501][101];

    for(int i = 0; i <= target; i++)
    {
        for(int j = 0; j <= K; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = coins[i]; j <= target; j++)
        {
            for(int k = 1; k <= K; k++)
            {
                dp[j][k] += dp[j - coins[i]][k - 1];
            }
        }
    }

    return dp[target][K];
}

int main()
{
    int n, target, K;
    cin >> n >> target >> K;

    int coins[20];

    for(int i = 0; i < n; i++)
        cin >> coins[i];

    cout << countWays(coins, n, target, K);

    return 0;
}
