#include <iostream>

using namespace std;

void solution() {
    double score;
    string s;
    cin >> s;

    score = max(0, 4 - (s[0]-'A'));

    if (s.length() > 1 && s[1] != '0')
        score += (s[1] == '+' ? 0.3 : -0.3);

    cout.precision(1);
    cout << fixed << score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}