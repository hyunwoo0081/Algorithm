#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
    string s;

    getline(cin, s);
    while (s.compare("END")) {
        reverse(s.begin(), s.end());
        cout << s << '\n';
        getline(cin, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}