#include <iostream>

using namespace std;

void solution() {
    string s;
    bool isHiss = false;

    cin >> s;
    for (int i = 1; i < s.length(); i++)
        isHiss |= s[i-1] == 's' && s[i] == 's';

    cout << (isHiss ? "hiss" : "no hiss");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}