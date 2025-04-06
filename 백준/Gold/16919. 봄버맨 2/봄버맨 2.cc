#include <iostream>
#define SIZE 200

using namespace std;

char maps[SIZE][SIZE];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void simulation(int R, int C, bool isBombState) {
    if (isBombState) {
        for (int y = 0; y < R; y++)
            for (int x = 0; x < C; x++)
                maps[y][x] = maps[y][x] == '.' ? 'O' : 'X';
        return;
    }

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (maps[y][x] != 'X')
                continue;

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny >= 0 && ny < R && nx >= 0 && nx < C && maps[ny][nx] != 'X') {
                    maps[ny][nx] = '.';
                }
            }

            maps[y][x] = '.';
        }
    }
}

void solution() {
    int R, C, N;
    string s;

    cin >> R >> C >> N;
    for (int y = 0; y < R; y++) {
        cin >> s;
        for (int x = 0; x < C; x++)
            maps[y][x] = s[x];
    }

    N = min(N-1, 4 + (N - 1) % 4);

    for (int i = 0; i < N; i++) {
        simulation(R, C, i % 2 == 0);
    }

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cout << (maps[y][x] == '.' ? '.' : 'O');
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