#include <iostream>

using namespace std;

char map[50][5][7];

void solution() {
    int N, a, b, cnt, minN;
    string s;

    cin >> N;
    for (int k = 0; k < N; k++) {
        for (int y = 0; y < 5; y++) {
            cin >> s;
            for (int x = 0; x < 7; x++)
                map[k][y][x] = s[x];
        }
    }

    minN = 987654321;
    a = b = 0;
    for (int i = 0; i < N-1; i++)
        for (int j = i+1; j < N; j++) {
            cnt = 0;
            for (int y = 0; y < 5; y++)
                for (int x = 0; x < 7; x++)
                    cnt += map[i][y][x] != map[j][y][x];

            if (minN > cnt) {
                minN = cnt;
                a = i;
                b = j;
            }
        }

    cout << a+1 << ' ' << b+1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}