#include <iostream>

using namespace std;

void solution() {
    string s;
    int i, j;
    bool isPel;

    cin >> s;
    while (s[0] != '#') {
        isPel = false;
        for (int k = 0; !isPel && k < s.length(); k++) {
            i = 0 + (k == 0);
            j = s.length()-1 - (k == s.length() - 1);

            while (i < j && s[i] == s[j]) {
                i += 1 + (i+1 == k);
                j -= 1 + (j-1 == k);
            }
            isPel = i >= j;

            if (isPel) {
                for (i = 0; i < s.length(); i++)
                    if (i != k)
                        cout << s[i];
                cout << '\n';
            }
        }

        if (!isPel)
            cout << "not possible\n";

        cin >> s;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}