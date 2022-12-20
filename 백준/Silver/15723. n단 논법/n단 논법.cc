#include <iostream>

using namespace std;

bool floyd[26][26] = {false};

void solution() {
    int n, m;
    char from, to;
    string s;

    cin >> n;
    while (n--) {
        cin >> from >> s >> to;
        floyd[from-'a'][to-'a'] = true;
    }

    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                if (floyd[i][k] && floyd[k][j])
                    floyd[i][j] = true;

    cin >> m;
    while (m--) {
        cin >> from >> s >> to;
        if (floyd[from-'a'][to-'a'])
            cout << "T\n";
        else
            cout << "F\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}