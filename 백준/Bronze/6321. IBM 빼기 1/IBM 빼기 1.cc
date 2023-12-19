#include <iostream>

using namespace std;

void solution() {
    int T;
    string s;

    cin >> T;
    for (int t = 1; t <= T; t++){
        cin >> s;
        cout << "String #" << t << '\n';
        for (auto c : s) {
            cout << (char) (c == 'Z' ? 'A' : c + 1);
        }

        if (t != T)
            cout << "\n\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}