#include <bits/stdc++.h>
using namespace std;
void BubbleSort(int s[], int e[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (e[j] > e[j + 1]) {
                swap(e[j], e[j + 1]);
                swap(s[j], s[j + 1]);
            }
        }
    }
}
int main() {
    int N;
    cin >> N;
    int s[1000], e[1000];
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i];
    }
    BubbleSort(s, e, N);
    int count = 1;
    int lastEnd = e[0];
    for (int i = 1; i < N; i++) {
        if (s[i] >= lastEnd) {
            count++;
            lastEnd = e[i];
        }
    }
    cout << count << endl;
}

