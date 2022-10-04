#include <iostream>

using namespace std;

void solution() {
    int T, N, tmp, cnt2, cnt5;

    cin >> T;
    while (T--) {
        cin >> N;

        cnt2 = cnt5 = 0;
        tmp = N;
        while (tmp > 1) {
            tmp /= 2;
            cnt2 += tmp;
        }

        tmp = N;
        while (tmp > 4) {
            tmp /= 5;
            cnt5 += tmp;
        }

        cout << min(cnt2, cnt5) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
