#include <iostream>

using namespace std;

void solution() {
    int T, C, P;

    cin >> T;
    while (T--) {
        cin >> C >> P;

        cout << C << ' ' << P << '\n';
        cout << C*P - (C-1)*2;

        if (T != 0) cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}