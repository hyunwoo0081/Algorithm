#include <iostream>

using namespace std;

void solution() {
    int T, c;
    string s;

    cin >> T;
    while (T--) {
        cin >> s;
        c = s.length() / 2;
        cout << (s[c-1] == s[c] ? "Do-it\n" : "Do-it-Not\n");
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}