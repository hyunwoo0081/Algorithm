#include <iostream>

using namespace std;

void solution() {
    int N;
    string s;

    cin >> N;
    while (N--) {
        cin >> s;
        if (6 <= s.length() && s.length() <= 9)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}