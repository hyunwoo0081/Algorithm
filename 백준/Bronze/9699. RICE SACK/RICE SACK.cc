#include <iostream>

using namespace std;

void solution() {
    int T, a, maxN;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 5; i++) {
            cin >> a;
            if (i == 0 || maxN < a)
                maxN = a;
        }
        cout << "Case #" << t << ": " << maxN << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}