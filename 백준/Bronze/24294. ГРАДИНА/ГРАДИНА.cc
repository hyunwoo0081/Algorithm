#include <iostream>

using namespace std;

void solution() {
    long long w1, w2, h1, h2;

    cin >> w1 >> h1 >> w2 >> h2;
    cout << 4 + 2 * (h1 + h2) + 2 * max(w1, w2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}