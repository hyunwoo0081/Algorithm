#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string &t, string &s) {
    if (t.length() == s.length())
        return t == s;

    bool result = false;
    if (s.back() == 'A') {
        s.pop_back();
        result |= compare(t, s);
        s.push_back('A');
    }
    if (!result && s.front() == 'B') {
        reverse(s.begin(), s.end());
        s.pop_back();
        result |= compare(t, s);
        s.push_back('B');
        reverse(s.begin(), s.end());
    }

    return result;
}

void solution() {
    string target, s;

    cin >> target >> s;
    cout << compare(target, s);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}