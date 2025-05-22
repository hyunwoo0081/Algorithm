#include <algorithm>
#include <iostream>

using namespace std;


void solution() {
    string s, s2;
    bool result = false;

    cin >> s >> s2;
    while (!s2.empty()) {
        s.push_back(s2.back());
        s2.pop_back();
    }

    for (int i = 0; i < 4; i++) {
        result |= (s == "HEPC" || s == "CPEH");
        s.push_back(s.front());
        s.erase(s.begin());
    }

    cout << (result ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}