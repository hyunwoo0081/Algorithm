#include <iostream>

using namespace std;

void solution() {
    string s;

    cin >> s;
    for (int i = s.length()-1; i >= 0; i--) {
        cout << s[s.length() - i - 1];
        if (i % 3 == 0 && i != 0)
            cout << ',';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}