#include <iostream>

using namespace std;

void solution() {
    int count;
    string s;

    getline(cin, s);
    while (s.length() != 1 || s[0] != '#') {
        count = 0;
        for (auto c : s)
            if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
                c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O')
                count++;

        cout << count << '\n';

        getline(cin, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}