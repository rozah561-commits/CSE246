#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    double BEG = 0, END = N;
    double mid;

    while (END - BEG > 1e-6) {
        mid = (BEG + END) / 2;

        if (mid * mid <= N) {
            BEG = mid;
        } else {
            END = mid;
        }
    }
    printf("%.3f\n", BEG);
    return 0;
}
