#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(i <= high && arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int j = partition(arr, low, high);
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Frequency Count:" << endl;
    int count = 1;
    for(int i = 1; i <= n; i++){
        if(i < n && arr[i] == arr[i - 1]){
            count++;
        } else {
            cout << arr[i - 1] << " Occurred " << count << " times" << endl;
            count = 1;
        }
    }
}
