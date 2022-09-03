#include <iostream>

using namespace std;

void solution() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        cout << s.front() << s.back() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}