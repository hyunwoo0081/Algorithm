#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> visited;
unordered_map<string, bool> isValid;
string map = ".........";

bool isSame(int a, int b, int c) {
    return map[a] != '.' && map[a] == map[b] && map[b] == map[c];
}

bool isFinished() {
    bool result = false;
    for (int i = 0; i < 3; ++i) {
        result |= isSame(3*i, 3*i + 1, 3*i + 2);
        result |= isSame(i, i + 3, i + 6);
    }
    result |= isSame(0, 4, 8);
    result |= isSame(2, 4, 6);
    if (result) return true;

    for (int i = 0; i < 9; ++i)
        if (map[i] == '.') return false;
    return true;
}

void makeString(int depth) {
    if (visited[map]) return;
    visited[map] = true;

    if (isFinished()) {
        isValid[map] = true;
        return;
    }

    for (int i = 0; i < 9; ++i) {
        if (map[i] == '.') {
            map[i] = depth%2 ? 'O' : 'X';
            makeString(depth+1);
            map[i] = '.';
        }
    }
}

void solution() {
    string s;
    makeString(0);

    cin >> s;
    while (s[0] != 'e') {
        cout << (isValid[s] ? "valid\n" : "invalid\n");
        cin >> s;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}