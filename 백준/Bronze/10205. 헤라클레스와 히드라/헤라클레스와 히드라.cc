#include <iostream>

using namespace std;

void solution() {
    int T, N;
    string s;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> s;

        for (auto c : s) {
            if (c == 'c')
                N++;
            else
                N--;
        }

        cout << "Data Set " << t << ":\n" << N;
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