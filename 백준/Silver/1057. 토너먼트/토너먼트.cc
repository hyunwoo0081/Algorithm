#include <iostream>

using namespace std;

int recursion(string &s, int l, int r) {
    if (l < r && s[l] == s[r])
        return recursion(s, l+1, r-1) + 1;
    return 1;
}

void solution() {
    int N, a, b;
    int count = 0;

    cin >> N >> a >> b;

    while (a != b) {
        a = (a+1) / 2;
        b = (b+1) / 2;
        count++;
    }

    cout << count;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}