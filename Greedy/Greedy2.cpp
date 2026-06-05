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
    int count = 0;
    for (int i = 0; i < N; i++)
        while (K >= coins[i]) {
            K -= coins[i];
            count++;
        }
    if (K > 0) return -1;
    return count;
}

int AltCoinChange(int N, int K, int coins[]) {
    int remaining = K;
    int count = 0;
    for (int i = 1; i < N; i++)
        while (remaining >= coins[i]) {
            remaining -= coins[i];
            count++;
        }
    if (remaining > 0) return -1;
    return count;
}
int main() {
    int N, K;
    cout << "Enter number of coins: ";
    cin >> N;
    cout << "Enter amount: ";
    cin >> K;

    int coins[100];
    cout << "Enter coins: ";
    for (int i = 0; i < N; i++) cin >> coins[i];

    BubbleSortDesc(coins, N);

    int greedyCoins = CoinChange(N, K, coins);
    int altCoins = AltCoinChange(N, K, coins);

    if (greedyCoins == -1 && altCoins == -1) {
        cout << "Both Impossible" << endl;
    }
    else if (greedyCoins != -1 && altCoins != -1) {
        if (greedyCoins < altCoins){
         cout << "Greedy" << endl;
        }
        else if (altCoins < greedyCoins) {
        cout << "Alternative" << endl;
        }
        else{
        cout << "Equal" << endl;
        }
    }
     else if (greedyCoins != -1){
     cout << "Greedy" << endl;
     }
    else {
    cout << "Alternative" << endl;
    }

}

