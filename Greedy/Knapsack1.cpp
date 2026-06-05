#include <bits/stdc++.h>
using namespace std;

void sortByRatio(double profit[], double weight[], int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            double ratio1 = profit[j] / weight[j];
            double ratio2 = profit[j + 1] / weight[j + 1];

            if (ratio1 < ratio2) {
                swap(profit[j], profit[j + 1]);
                swap(weight[j], weight[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(int n, double capacity,
                           double profit[], double weight[]) {

    double totalProfit = 0.0;

    sortByRatio(profit, weight, n);

    for (int i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            totalProfit += profit[i];
        } else {
            totalProfit += profit[i] * (capacity / weight[i]);
            break;
        }
    }

    return totalProfit;
}

int main() {

    int n;
    double capacity;
    cin >> n >> capacity;

    double profit[1000], weight[1000];

    for (int i = 0; i < n; i++)
        cin >> profit[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    double result = fractionalKnapsack(n, capacity, profit, weight);

    cout << result << endl;
}
