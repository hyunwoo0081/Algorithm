#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int failure[1000000];

void solution() {
    string s;

    cin >> s;
    while(s.size() > 1 || s[0] != '.') {
        int j = 0;
        for (int i = 1; i < s.size(); ++i) {
            failure[i] = 0;
            if (j > 0 && s[i] != s[j])
                j = failure[j-1];

            if (s[i] == s[j])
                failure[i] = ++j;
        }

        int minRepeat = s.size() - failure[s.size()-1];

        if (s.size() % minRepeat == 0)
            cout << (s.size() / minRepeat) << '\n';
        else
            cout << 1 << '\n';

        cin >> s;
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}