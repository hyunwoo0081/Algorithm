#include <iostream>

using namespace std;

void solution() {
    int T, a, result = 0;

    cin >> T;
    while (T--) {
        cin >> a;

        result += a / 2 + a % 2;
    }
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}