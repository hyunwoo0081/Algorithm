#include <iostream>

using namespace std;

void solution() {
    int N, M, K, round = 0, si;

    cin >> N >> M >> K;
    round = 0;
    for (int i = 1; i < N; i *= 2) {
        round++;
    }

    si = 0;
    for (int i = 2; i <= K; i *= 2) {
        si++;
    }

    cout << min(round, si+M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}