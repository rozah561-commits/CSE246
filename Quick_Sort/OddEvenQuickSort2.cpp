#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int oddCount = n / 2;
    int odd[oddCount];
    int k = 0;
    for (int i = 1; i < n; i += 2)
        odd[k++] = arr[i];

    quickSort(odd, 0, oddCount - 1);

    k = 0;
    for (int i = 1; i < n; i += 2)
        arr[i] = odd[k++];

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

}
