#include <iostream>

using namespace std;

void solution() {
    int keyLen;
    string s, key;

    getline(cin, s);
    cin >> key;

    keyLen = key.length();
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') cout << ' ';
        else cout << (char)((s[i] - key[i%keyLen] - 1 + 26) % 26 + 'a');
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}