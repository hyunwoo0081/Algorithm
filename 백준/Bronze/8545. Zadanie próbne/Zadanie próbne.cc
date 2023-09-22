#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
    string s;

    cin >> s;
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}