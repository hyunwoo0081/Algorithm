#include <iostream>

using namespace std;

void solution() {
    string s;
    bool rated = false;

    getline(cin, s);
    for (int i = 0; i < s.length()-1; i++)
        rated |= (s[i] == 'd' || s[i] == 'D') && s[i+1] == '2';
    cout << (rated ? "D2" : "unrated");
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}