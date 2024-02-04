#include <iostream>

using namespace std;

string arr;
bool counts[10] = {false};

void solution() {
    int T, cntA, cntS;
    string s;

    cin >> arr >> T;
    for (auto a : arr)
        counts[a - '0'] = true;

    while (T--) {
        cin >> s;

        cntA = cntS = 0;
        for (int i = 0; i < 4; i++) {
            cntA += arr[i] == s[i];
            cntS += counts[s[i] - '0'];
        }

        cout << cntS << ' ' << cntA << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}