#include <iostream>
#define SIZE 1'000'000

using namespace std;

long long arr[SIZE] = {0};
long long prefix[SIZE] = {0};

void solution() {
    long long L, d, i, mi = 0, m = 0;

    cin >> L;
    for (i = 0; i < L; i++) {
        cin >> arr[i];
    }

    // for (d = L; d > L/2; d--) {
    //     prefix[d-1] = arr[d-1];
    //
    //     if (prefix[d-1] >= m) {
    //         m = prefix[d-1];
    //         mi = d;
    //     }
    // }
    //
    // for (; d > 0; d--) {
    //     prefix[d-1] = prefix[d*2-1];
    //     for (i = d-1; i < L; i += d*2) {
    //         prefix[d-1] += arr[i];
    //     }
    //
    //     if (prefix[d-1] >= m) {
    //         m = prefix[d-1];
    //         mi = d;
    //     }
    // }

    for (d = 1; d <= L; d++) {
        prefix[d-1] = 0;
        for (i = d-1; i < L; i += d)
            prefix[d-1] += arr[i];

        if (prefix[d-1] > m) {
            m = prefix[d-1];
            mi = d;
        }
    }

    // if (m == 0) mi = 0;

    cout << mi << ' ' << m;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}