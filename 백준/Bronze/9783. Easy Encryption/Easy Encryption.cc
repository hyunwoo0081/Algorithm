#include <iostream>

using namespace std;

void solution() {
    string s;

    getline(cin, s);
    for (auto c : s) {
        if ('a' <= c && c <= 'z')
            cout << (c-'a'+1 < 10 ? "0" : "") << c-'a'+1;
        else if ('A' <= c && c <= 'Z')
            cout << c-'A'+27;
        else if ('0' <= c && c <= '9')
            cout << '#' << c;
        else
            cout << c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}