#include <iostream>

using namespace std;

void solution() {
    long long S, N, M, T, a, size;

    cin >> S >> N >> M;
    size = 0;
    T = N + M;
    while (T--) {
        cin >> a;
        size += a == 1 ? 1 : -1;
        if (size > S)
            S *= 2;
    }

    cout << S;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}