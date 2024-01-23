#include <iostream>

using namespace std;

void solution() {
    int T, N, a, b, cnt, result;

    cin >> T >> N;
    result = cnt = 0;
    while (T--) {
        cin >> a >> b;
        cnt += a - b;

        result = max(result, max(0, cnt-N));
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}