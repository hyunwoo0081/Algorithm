#include <iostream>

using namespace std;

char maps[100][100];

void solution() {
    int N, M, cnt;
    bool isCounted;

    cin >> N >> M;
    for (int n = 0; n < N; n++)
        cin >> maps[n];

    for (int n = 0; n < N; n++) {
        cnt = 0;
        isCounted = false;
        for (int m = 0; m < M; m++) {
            if (maps[n][m] == '#') {
                cnt++;
                isCounted = true;
            }
            else if (cnt > 0 && maps[n][m] != '#') {
                cout << cnt << ' ';
                cnt = 0;
            }
        }
        if (cnt > 0)
            cout << cnt << ' ';
        else if (!isCounted)
            cout << 0;
        cout << '\n';
    }

    for (int m = 0; m < M; m++) {
        cnt = 0;
        isCounted = false;
        for (int n = 0; n < N; n++) {
            if (maps[n][m] == '#') {
                cnt++;
                isCounted = true;
            }
            else if (cnt > 0 && maps[n][m] != '#') {
                cout << cnt << ' ';
                cnt = 0;
            }
        }
        if (cnt > 0)
            cout << cnt << ' ';
        else if (!isCounted)
            cout << 0;
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}