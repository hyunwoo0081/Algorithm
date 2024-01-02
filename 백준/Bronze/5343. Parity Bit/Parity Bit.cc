#include <iostream>

using namespace std;

void solution() {
    int T, cnt, error;
    string s;

    cin >> T;
    while (T--) {
        error = 0;
        cin >> s;
        for (int i = 0; i < s.length()/8; i++) {
            cnt = 0;
            for (int j = i*8; j < i*8+8;j++) {
                cnt += s[j] == '1';
            }
            error += cnt % 2;
        }
        cout << error << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}