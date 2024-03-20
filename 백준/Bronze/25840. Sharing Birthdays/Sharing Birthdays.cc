#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> exists;
void solution() {
    int T;
    string s;

    cin >> T;
    while (T--) {
        cin >> s;
        exists[s] = true;
    }

    cout << exists.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}