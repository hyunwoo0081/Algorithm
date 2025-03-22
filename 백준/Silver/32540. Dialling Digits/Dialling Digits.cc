#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> arr[11];
vector<string> v;

char getMnemonic(char c) {
    if (c <= 'o')
        return (c - 'a') / 3 + '2';
    if (c <= 's')
        return '7';
    if (c <= 'v')
        return '8';
    return '9';
}

void solution() {
    int N, T;
    string s;

    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> s;
        arr[s.size()].push_back(s);
    }

    for (auto &v : arr) {
        sort(v.begin(), v.end());
    }

    while (T--) {
        cin >> s;

        v.clear();
        int size = s.size();
        for (auto &vec : arr[size]) {
            bool isSame = true;
            for (int i = 0; i < size; i++) {
                isSame &= s[i] == getMnemonic(vec[i]);
            }

            if (isSame) {
                v.push_back(vec);
            }
        }

        cout << v.size();
        for (auto &str : v) {
            cout << ' ' << str;
        }
        cout << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}