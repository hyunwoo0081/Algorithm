#include <iostream>

using namespace std;

void solution() {
    int T, a, b;

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> a >> b;
        cout << "Case " << i << ": " << a+b << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}