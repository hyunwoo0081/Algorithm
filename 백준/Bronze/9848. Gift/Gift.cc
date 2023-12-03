#include <iostream>

using namespace std;

void solution() {
    int T, N, prev, a, cnt = 0;

    cin >> T >> N >> prev;
    for (int t = 1; t < T; t++) {
        cin >> a;

        if (prev - a >= N)
            cnt++;
        prev = a;
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}