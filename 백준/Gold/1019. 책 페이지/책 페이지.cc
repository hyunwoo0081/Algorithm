#include <iostream>

using namespace std;

typedef long long ll;

ll result[10] = {0};

void addNum(int N, ll r) {
    while (N > 0) {
        result[N%10] += r;
        N /= 10;
    }
}

void addCount(int N) {
    ll r = 1;
    while (N > 0) {
        while (N > 0 && N % 10 != 9) {
            addNum(N--, r);
        }
        if (N <= 0) return;

        for (int i = 0; i < 10; ++i) {
            result[i] += (N/10+ !!i)*r;
        }

        r *= 10;
        N /= 10;
    }
}

void solution() {
    int N;
    cin >> N;
    addCount(N);

    for (ll res : result)
        cout << res << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}