#include <iostream>

using namespace std;

void solution() {
    int coin[] = {25, 10, 5, 1};
    int T, cost;

    cin >> T;
    while (T--) {
        cin >> cost;

        cout << cost/coin[0] << ' ';
        cost %= coin[0];
        cout << cost/coin[1] << ' ';
        cost %= coin[1];
        cout << cost/coin[2] << ' ';
        cost %= coin[2];
        cout << cost/coin[3] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
