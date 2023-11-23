#include <iostream>

using namespace std;

void solution() {
    int P, N, K;

    cin >> P;
    while (P--) {
        cin >> N >> K;
        cout << N << ' ' << K*(K+1)/2 + K << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}