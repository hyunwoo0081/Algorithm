#include <iostream>
#include <cmath>

using namespace std;

void solution() {
    int L, l1, l2, sq, s;

    cin >> L >> l1 >> l2;
    sq = (L*L - l1*l1)*(L*L - l2*l2);
    s = l1*l2;

    if (sq < 0 || sq <= s*s) {
        cout << -1;
    } else {
        cout << (sqrt(sq) - s) / L;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}