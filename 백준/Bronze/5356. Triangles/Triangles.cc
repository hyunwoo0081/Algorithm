#include <iostream>

using namespace std;

void solution() {
    int T, N;
    char c, s;

    cin >> T;
    while (T--) {
        cin >> N >> c;

        for (int i = 0; i < N; i++) {
            s = ((c + i - 'A') % ('Z' - 'A' + 1)) + 'A';
            for (int j = 0; j <= i; j++)
                cout << s;
            cout << '\n';
        }
        cout << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}