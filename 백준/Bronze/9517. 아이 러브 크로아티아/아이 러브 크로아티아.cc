#include <iostream>

using namespace std;

void solution() {
    long long player, T, t, passT;
    char ans;

    passT = 0;
    cin >> player >> T;
    while (T--) {
        cin >> t >> ans;
        passT += t;

        if (passT >= 210) {
            cout << player;
            return;
        }

        if (ans == 'T')
            player = player % 8 + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}