#include <iostream>

using namespace std;

void solution() {
    int maxCnt;
    int counts[26] = {0};
    string s;

    while (getline(cin, s)) {
        for (auto c : s)
            if (c != ' ') counts[c - 'a']++;
    }

    maxCnt = 0;
    for (auto a : counts)
        maxCnt = max(maxCnt, a);

    for (int i = 0; i < 26; i++) {
        if (counts[i] == maxCnt)
            cout << (char)('a' + i);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}