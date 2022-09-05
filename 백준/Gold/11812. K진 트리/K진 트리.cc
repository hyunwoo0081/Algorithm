#include <iostream>

using namespace std;

long long getParent(long long x, int K) {
    return (x - 2) / K + 1;
}

void solution() {
    long long N, x, y, count;
    int K, Q;

    cin >> N >> K >> Q;
    while (Q--) {
        cin >> x >> y;

        if (K == 1) {
            cout << max(x, y) - min(x, y) << '\n';
            continue;
        }

        count = 0;
        while (x != y) {
            if (x > y)
                x = getParent(x, K);
            else
                y = getParent(y, K);
            count++;
        }
        cout << count << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}