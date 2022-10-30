#include <iostream>

using namespace std;

void solution() {
    int T, n, q, p;
    long long s;

    cin >> T;
    while (T--) {
        cin >> s >> n;
        while (n--) {
            cin >> q >> p;
            s += q * p;
        }
        cout << s << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}