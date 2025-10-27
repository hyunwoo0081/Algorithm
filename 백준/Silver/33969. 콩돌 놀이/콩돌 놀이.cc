#include <iostream>

using namespace std;

void solution() {
    int N, M, blacks = 0;
    string s;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++)
            blacks += s[j] == 'x';
    }

    for (int i = 0; i <= blacks/9; i++) {
        if ((blacks - 9*i) % 11 == 0) {
            cout << (blacks - 9*i)/11 << ' ' << i;
            return;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}
