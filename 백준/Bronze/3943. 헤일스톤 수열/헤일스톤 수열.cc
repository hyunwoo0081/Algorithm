#include <iostream>

using namespace std;

void solution() {
    long long T, n, maxN;

    cin >> T;
    while (T--) {
        cin >> n;
        maxN = n;
        while (n != 1) {
            if (n % 2)
                n = 3*n + 1;
            else
                n /= 2;
            maxN = max(maxN, n);
        }
        cout << maxN << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}