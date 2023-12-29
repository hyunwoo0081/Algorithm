#include <iostream>

using namespace std;

void solution() {
    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++)
                cout << (x == 0 || x == N-1 || y == 0 || y == N-1 ? '#' : 'J');
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