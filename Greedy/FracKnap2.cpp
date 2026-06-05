#include <bits/stdc++.h>
using namespace std;

void sortByRatio(double weight[], double profit[], int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n-i-1; j++){
            if ((profit[j] / weight[j]) < (profit[j+1] / weight[j+1])){
                double temp1 = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp1;

                double temp2 = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp2;
            }
        }
    }
}
double fractionalKnapsack(double weight[], double profit[], int n, double W,
                           int &wholeItems, int &fractionalItems)
{
    double totalProfit = 0.0;
    wholeItems = 0;
    fractionalItems = 0;
    for (int i = 0; i < n; i++)
    {
        if (W == 0)
            break;

        if (weight[i] <= W)
        {
            totalProfit += profit[i];
            W -= weight[i];
            wholeItems++;
        }
        else
        {
            totalProfit = totalProfit + profit[i] * (W / weight[i]);
            fractionalItems = 1;
            W = 0;
        }
    }
    return totalProfit;
}
int main()
{
    int n;
    double W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;
    double weight[100], profit[100];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> weight[i];

        cout << "Enter profit of item " << i + 1 << ": ";
        cin >> profit[i];
    }
    sortByRatio(weight, profit, n);
    int wholeItems, fractionalItems;
    double totalProfit = fractionalKnapsack(weight, profit, n, W,
                                            wholeItems, fractionalItems);
    cout << fixed << setprecision(2);
    cout << "Maximum Profit: " << totalProfit << endl;
    cout << "Whole Items: " << wholeItems << endl;
    cout << "Fractional Items: " << fractionalItems << endl;
    return 0;
}
