#include <iostream>

using namespace std;

void solution() {
    int t, s;
    cin >> t >> s;

    cout << (12 <= t && t <= 16 && !s ? 320 : 280);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}