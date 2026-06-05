#include <bits/stdc++.h>
using namespace std;

int upperBound(int A[], int N, int S) {
    int BEG = 0,
     END = N - 1;
    int ans = N;

    while (BEG <= END) {
        int mid = (BEG + END) / 2;

        if (A[mid] > S) {
            ans = mid;
            END = mid - 1;
        } else {
            BEG = mid + 1;
        }
    }
    return ans;
}

int lowerBound(int A[], int N, int S) {
    int BEG = 0,
    END = N - 1;
    int ans = 0;

    while (BEG <= END) {
        int mid = (BEG + END) / 2;

        if (A[mid] <= S) {
            ans = mid;
            BEG = mid + 1;
        } else {
            END = mid - 1;
        }
    }
    return ans;
}

int main() {
    int N, S;
    cin >> N >> S;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ub = upperBound(A, N, S);
    int lb = lowerBound(A, N, S);

    cout << ub << " " << lb << endl;
}

