#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(int A[], int trgt ,int N) {
    int BEG = 0,
    END = N - 1;
    int f = -1;

    while (BEG <= END) {
        int mid = (BEG + END) / 2;

        if (A[mid] == trgt) {
            f = mid;
            END = mid - 1;
        }
        else if (A[mid] < trgt) {
            BEG = mid + 1;
        }
        else {
            END = mid - 1;
        }
    }
    return f;
}

int lastOccurrence(int A[], int trgt, int N) {
    int BEG = 0,
    END = N - 1;
    int l = -1;

    while (BEG <= END) {
        int mid = (BEG + END) / 2;

        if (A[mid] == trgt) {
            l = mid;
            BEG = mid + 1;
        }
        else if (A[mid] < trgt) {
            BEG = mid + 1;
        }
        else {
            END = mid - 1;
        }
    }
    return l;
}

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int trgt;
    cin >> trgt;

    int f = firstOccurrence(A,trgt,N);
    int l = lastOccurrence(A,trgt,N);

    cout << f << " " << l << endl;
}

