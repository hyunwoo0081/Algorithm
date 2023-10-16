#include <iostream>

using namespace std;

void solution() {
    int N, K;

    cin >> N;
    K = 1;
    while (K*K + K + 1 != N)
        K++;
    cout << K;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}