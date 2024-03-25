#include <iostream>

using namespace std;

void solution() {
    int T, V, E;

    cin >> T;
    while (T--) {
        cin >> V >> E;
        cout << 2 - V + E << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}