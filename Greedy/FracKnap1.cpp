#include <bits/stdc++.h>
using namespace std;

void sortByRatio(double profit[], double weight[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((profit[j] / weight[j]) < (profit[j + 1] / weight[j + 1]))
            {
                 double temp1=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp1;

               double temp2=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp2;
            }
        }
    }
}

double fractionalKnapsack(double profit[], double weight[], double frac[], int n, double W)
{
    double totalProfit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (W == 0)       //W=maximum weight,Capacity
        {
            frac[i] = 0.0;
            continue;
        }

        if (weight[i] <= W)
        {
            frac[i] = 1.0;
            totalProfit += profit[i];
            W -= weight[i];
        }
        else
        {
            frac[i] = W / weight[i];
            totalProfit += profit[i] * frac[i];
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
    double profit[100], weight[100], frac[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight of item " << i + 1 << ": ";
        cin >> profit[i] >> weight[i];
        frac[i] = 0.0;
    }
    if (W == 0)
    {
        cout << fixed << setprecision(2);
        cout << "Maximum Profit: 0.00" << endl;
        cout << "Fractions: ";
        for (int i = 0; i < n; i++)
            cout << "0.00 ";
        cout << endl;
        return 0;
    }
    sortByRatio(profit, weight, n);
    double totalProfit = fractionalKnapsack(profit, weight, frac, n, W);

    cout << fixed << setprecision(2);
    cout << "Maximum Profit: " << totalProfit << endl;
    cout << "Fractions: ";

    for (int i = 0; i < n; i++)
        cout << frac[i] << " ";
    cout << endl;
}
