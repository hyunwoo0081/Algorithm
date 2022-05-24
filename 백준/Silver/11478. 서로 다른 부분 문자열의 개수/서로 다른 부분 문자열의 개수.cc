#include <iostream>
#include <unordered_map>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

unordered_map<string, bool> isExist;

void solution() {
    string s, sub;
    cin >> s;

    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
        sub.clear();
        for (int j = i; j < s.length(); ++j) {
            sub.push_back(s[j]);
            if (!isExist[sub]) {
                isExist[sub] = true;
                count++;
            }
        }
    }

    cout << count;
}

int main() {
    fastIO();
    solution();

    return 0;
}