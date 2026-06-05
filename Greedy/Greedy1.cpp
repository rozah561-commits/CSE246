#include <bits/stdc++.h>
using namespace std;

void BubbleSortDesc(int coins[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }
}

int CoinChange(int N, int K, int coins[]) {
    int amount = K;
    int count = 0;
    for (int i = 0; i < N; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return count;
}

int main() {
    int N, K;

    cout << "Enter number of coins: ";
    cin >> N;

    cout << "Enter amount: ";
    cin >> K;

    int coins[N];
    cout << "Enter coins: ";
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    BubbleSortDesc(coins, N);
    int result = CoinChange(N, K, coins);
    cout << "Minimum coins needed: " << result << endl;

}
