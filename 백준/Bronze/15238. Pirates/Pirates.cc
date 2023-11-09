#include <iostream>

using namespace std;

int counts[26] = {0};

void solution() {
    int N, maxI;
    string s;

    cin >> N >> s;
    for (auto c : s)
        counts[c-'a']++;

    maxI = 0;
    for (int i = 1; i < 26; i++) {
        if (counts[maxI] < counts[i])
            maxI = i;
    }

    cout << (char) ('a'+ maxI) << ' ' << counts[maxI];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}