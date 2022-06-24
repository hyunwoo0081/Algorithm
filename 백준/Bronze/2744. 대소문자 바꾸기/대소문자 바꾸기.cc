#include <iostream>

using namespace std;

void solution() {
    string s;

    cin >> s;
    for (auto c: s) {
        cout << (char) (c <= 'Z' ? c-'A'+'a' : c-'a'+'A');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}