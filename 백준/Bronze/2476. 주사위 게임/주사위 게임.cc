#include <iostream>

using namespace std;

void solution() {
    long long T, a, b, c, maxN = 0;

    cin >> T;
    while (T--) {
        cin >> a >> b >> c;

        if (a == b && b == c)
            maxN = max(maxN, 10000 + a*1000);
        else if (a == b || b == c || c == a)
            maxN = max(maxN, 1000 + (a == b ? a : c)*100);
        else
            maxN = max(maxN, max(a, max(b, c))*100);
    }
    cout << maxN;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}