#include <iostream>

using namespace std;

void solution() {
    int N, prev, t, result;

    cin >> N;
    if (N % 2) {
        cout << "still running";
        return;
    }

    result = 0;
    for (int i = 0; i < N; i += 2) {
        cin >> prev >> t;
        result += t - prev;
    }

    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}