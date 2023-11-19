#include <iostream>

using namespace std;

void solution() {
    int N, a, b, c, sa, sb, sc, sold;

    sa = sb = sc = 0;
    cin >> N;
    while (N--) {
        cin >> a >> b >> c;

        sa += a;
        sb += b;
        sc += c;
        sold = min(min(sa, sb), sc);

        if (sold >= 30) {
            cout << sold << '\n';
            sa -= sold;
            sb -= sold;
            sc -= sold;
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}