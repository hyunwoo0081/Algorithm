#include <iostream>

using namespace std;

int recursion(string &s, int l, int r) {
    if (l < r && s[l] == s[r])
        return recursion(s, l+1, r-1) + 1;
    return 1;
}

void solution() {
    int T, counts;
    string s;

    cin >> T;
    while (T--) {
        cin >> s;

        counts = recursion(s, 0, s.length()-1);
        cout << (counts == s.length()/2 + 1) << ' ' << counts << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}