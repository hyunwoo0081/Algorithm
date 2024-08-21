#include <iostream>

using namespace std;

void solution() {
    long long N, r, n, tmp, result = 0;

    cin >> N;
    r = 1;
    for (n = 0; r <= N; n++) {
        r *= 10;
    }
    r /= 10;

    for (int i = 0; i < n; i++) {
        result += N;
        tmp = N % 10;
        N = N / 10 + tmp * r;
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}