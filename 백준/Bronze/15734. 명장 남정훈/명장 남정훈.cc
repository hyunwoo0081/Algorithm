#include <iostream>

using namespace std;

void solution() {
    int l, r, c, result, tmp;

    cin >> l >> r >> c;

    tmp = min(l, r);
    result = tmp * 2;
    l -= tmp;
    r -= tmp;

    tmp = min(max(l, r), c);
    result += tmp * 2;
    c -= tmp;

    c /= 2;
    result += c * 2;

    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}