#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
    bool isPel = true;
    int i, j;
    string s;

    cin >> s;
    i = 0, j = s.length()-1;
    while (i < j) {
        if (s[i] != s[j]) {
            isPel = false;
            break;
        }
        i++, j--;
    }

    cout << isPel;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}