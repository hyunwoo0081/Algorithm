#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void solution() {
    int Tc;
    string s;

    cin >> Tc;
    while (Tc--) {
        cin >> s;
        bool flag = true;
        for (int i = 0; i < s.length(); ++i) {
            if (i <= s.length()-2 && s[i] == '0' && s[i+1] == '1') {
                i++;
            }
            else if (i <= s.length()-4 && s[i] == '1' && s[i+1] == '0' && s[i+2] == '0') {
                i += 2;
                while (i < s.length() && s[i] == '0') i++;
                if (i >= s.length()) {
                    flag = false;
                    break;
                }

                while(i < s.length() && s[i] == '1') i++;
                i--;
                if (i <= s.length()-4 && s[i-1] == '1' && s[i] == '1' && s[i+1] == '0' && s[i+2] == '0')
                    i--;
            }
            else {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}