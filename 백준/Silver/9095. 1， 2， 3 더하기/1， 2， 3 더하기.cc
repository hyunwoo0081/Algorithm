#include <iostream>

using namespace std;
typedef long long ll;

ll getCount(int n) {
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    ll sum = 0;
    for (int i = 1; i <= 3; i++) {
        sum += getCount(n-i);
    }

    return sum;
}

void solution() {
    ll T, n;

    cin >> T;
    while (T--) {
        cin >> n;
        cout << getCount(n) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}