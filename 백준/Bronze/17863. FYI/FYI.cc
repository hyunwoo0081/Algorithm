#include <iostream>

using namespace std;

void solution() {
    string s;
    cin >> s;

    if (s[0] == '5' && s[1] == '5' && s[2] == '5')
        cout << "YES";
    else
        cout << "NO";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}