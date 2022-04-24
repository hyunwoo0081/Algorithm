#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool isPel(string &s, int i, int j) {
    while (0 <= i && j < s.size()) {
        if (s[i] != s[j]) return false;
        i--, j++;
    }
    return true;
}

void solution() {
    string s;

    cin >> s;

    for (int k = s.size(); k < s.size()*2; ++k) {
        if (isPel(s, (k-1)/2, k/2)) {
            cout << k;
            return;
        }
    }

    cout << s.size()*2-1;
}


int main() {
    fastIO();
    solution();

    return 0;
}