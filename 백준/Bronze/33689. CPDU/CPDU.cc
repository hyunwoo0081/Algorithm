#include <iostream>

using namespace std;

void solution() {
    int T, cnt = 0;
    string s;

    cin >> T;
    while (T--) {
        cin >> s;
        cnt += s[0] == 'C';
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}