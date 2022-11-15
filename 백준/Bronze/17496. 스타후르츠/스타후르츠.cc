#include <iostream>

using namespace std;

void solution() {
    int N, T, C, P;

    cin >> N >> T >> C >> P;
    cout << (N-1)/T * C * P;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
