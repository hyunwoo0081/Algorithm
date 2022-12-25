#include <iostream>

using namespace std;

void solution() {
    string s1, s2, op;

    cin >> s1 >> op >> s2;
    if (op[0] == '*') {
        cout << 1;
        for (int i = 0; i < s1.length() + s2.length() - 2; i++)
            cout << 0;
    }
    else {
        if (s1.length() == s2.length()) {
            cout << 2;
            for (int i = 0; i < s1.length()-1; i++)
                cout << 0;
        }
        else if (s1.length() > s2.length()) {
            cout << 1;
            for (int i = s1.length()-1; i > 0; i--)
                cout << (i == s2.length());
        }
        else {
            cout << 1;
            for (int i = s2.length()-1; i > 0; i--)
                cout << (i == s1.length());
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}