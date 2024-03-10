#include <iostream>

using namespace std;

void solution() {
    int T, sum, a;
    string s;

    cin >> T;
    cin.ignore();

    while (T--) {
        getline(cin, s);

        sum = 0;
        a = 0;
        for (auto c : s) {
            if (c == ' ') {
                sum += a;
                a = 0;
            }
            else {
                a = a * 10 + c - '0';
            }
        }
        sum += a;
        
        cout << sum << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}