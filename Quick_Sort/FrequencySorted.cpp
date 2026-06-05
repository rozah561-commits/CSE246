#include <bits/stdc++.h>
using namespace std;

int PARTITION(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
        }
    }
    int temp1 = arr[low];
    arr[low] = arr[j];
    arr[j] = temp1;

    return j;
}

void QUICK_SORT(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = PARTITION(arr, low, high);
        QUICK_SORT(arr, low, pivot_index - 1);
        QUICK_SORT(arr, pivot_index + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    QUICK_SORT(arr, 0, n - 1);

    int m = 0, freq[n], num[n];

    for (int i = 0; i < n; i++)
    {
        bool copied = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                copied = true;
                break;
            }
        }
        if (copied == true)
        {
            continue;
        }

        num[m] = arr[i];
        freq[m] = 0;

        for (int k = 0; k < n; k++)
        {
            if (arr[i] == arr[k])
            {
                freq[m]++;
            }
        }
        m++;
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (freq[i] < freq[j] || (freq[i] == freq[j] && num[i] > num[j]))
            {
                int temp1 = freq[i];
                freq[i] = freq[j];
                freq[j] = temp1;

                int temp2 = num[i];
                num[i] = num[j];
                num[j] = temp2;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < freq[i]; j++)
        {
            cout << num[i] << " ";
        }
    }
    cout << endl;

}

