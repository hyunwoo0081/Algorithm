#include <iostream>

using namespace std;

void solution() {
    bool isPos = true;
    string s;

    cin >> s;
    for (int i = 0; i < s.length(); i++) {

        if (i+1 < s.length() && s[i] == 'p' && s[i+1] == 'i') {
            i += 1;
        }
        else if (i+1 < s.length() && s[i] == 'k' && s[i+1] == 'a') {
            i += 1;
        }
        else if (i+2 < s.length() && s[i] == 'c' && s[i+1] == 'h' && s[i+2] == 'u') {
            i += 2;
        }
        else {
            isPos = false;
            break;
        }
    }

    cout << (isPos ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}