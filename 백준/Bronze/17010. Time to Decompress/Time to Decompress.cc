#include <iostream>

using namespace std;

void solution() {
    int T, N;
    char c;

    cin >> T;
    while (T--) {
        cin >> N >> c;
        while (N--) {
            cout << c;
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