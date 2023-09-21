#include <iostream>

using namespace std;

int bronzeSilver[] = {0, 1, 0, 0, 2, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 2, 1, 0, 0, 1, 0, 0, 0, 1};
int counts[26] = {0};

void solution() {
    string s;
    int maxN;

    cin >> maxN >> s;
    for (auto c : s)
        counts[c-'A']++;

    for (int i = 0; i < 26; i++) {
        if (bronzeSilver[i] > 0)
            maxN = min(maxN, counts[i]/bronzeSilver[i]);
    }

    cout << maxN;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}