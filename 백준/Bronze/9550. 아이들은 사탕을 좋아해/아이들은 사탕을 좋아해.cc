#include <iostream>

using namespace std;

void solution() {
    int T, N, K, a, count;

    cin >> T;
    while (T--) {
        count = 0;
        cin >> N >> K;
        while (N--) {
            cin >> a;
            count += a / K;
        }
        cout << count << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}