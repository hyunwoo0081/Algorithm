#include <iostream>

using namespace std;
typedef long long ll;

void solution() {
    ll N, k, s, result = 0;

    cin >> N >> k;
    result = s = N;

    while (k--) {
        s *= 10;
        result += s;
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}