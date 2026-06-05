#include <bits/stdc++.h>
using namespace std;

void sortDescending(int coins[], int N) {
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
int main() {
    int N;
    cin >> N;
    int coins[1000];
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int Amount;
    cin >> Amount;

    sortDescending(coins, N);

    int used[10000];
    int count = 0;

    for (int i = 0; i < N; i++) {
        while (Amount >= coins[i]) {
            used[count] = coins[i];
            count++;
            Amount =Amount - coins[i];
        }
    }
    cout << "Coins Used: ";
    for (int i = 0; i < count; i++) {
        cout << used[i] << " ";
    }
    cout << endl;
    cout << "Total Coins Needed: " << count << endl;
}
