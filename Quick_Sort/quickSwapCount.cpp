#include<bits/stdc++.h>
using namespace std;

int swapCount = 0;

int partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l;
    int j = h;

    while(i < j){
        while(i <= h && A[i] <= pivot){
            i++;
        }
        while(A[j] > pivot){
            j--;
        }
        if(i < j){
            swap(A[i], A[j]);
            swapCount++;
        }
    }

    swap(A[l], A[j]);
    swapCount++;

    return j;
}

void quickSort(int A[], int l, int h) {
    if (l < h) {
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}

int main() {
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    quickSort(A, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    cout << "\nTotal Swaps: " << swapCount;

    return 0;
}
