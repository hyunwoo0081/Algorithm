#include <iostream>

using namespace std;

void solution() {
    int j, t;
    string s;

    t = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (t == 0) {
            cout << s[i];
            t = s[i] - 'A' + 1;
        }
        t--;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}