#include <iostream>

using namespace std;

const string arr[] = {
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you",
    "Never gonna stop"
};

void solution() {
    int T;
    string s;
    bool result = true, isMatched = false;

    cin >> T;
    cin.ignore();
    while (T--) {
        getline(cin, s);

        isMatched = false;
        for (auto &i : arr) {
            isMatched |= s == i;
        }

        result &= isMatched;
    }

    result = !result;
    cout << (result ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}