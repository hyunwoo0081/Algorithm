#include <iostream>

using namespace std;

void solution() {
    int T, W, start, i, lines, len;
    string s;

    cin >> T;
    while (T--) {
        cin >> W;
        cin.ignore();
        getline(cin, s);

        len = s.length();
        start = lines = 0;
        while (start < len) {
            i = start + W;
            while (i < len && s[i] != ' ') i--;
            i++;

            start = i;
            lines++;
        }

        cout << lines << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}