#include <iostream>

using namespace std;

bool checks[26] = {false};

void solution() {
    string s;

    cin >> s;
    for (auto c : s) {
        checks[c-'A'] = true;
    }

    for (int i = 0; i < 26; i++) {
        if (!checks[i]) {
            cout << (char)(i + 'A');
            return;
        }
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}