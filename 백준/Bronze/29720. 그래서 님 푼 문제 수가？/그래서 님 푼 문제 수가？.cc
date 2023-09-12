#include <iostream>

using namespace std;

void solution() {
    int N, M, K;

    cin >> N >> M >> K;
    cout << max(0, N - M*K) << ' ' << max(0, N - M*(K-1) - 1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}