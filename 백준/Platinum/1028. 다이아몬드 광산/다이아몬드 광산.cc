#include <iostream>

using namespace std;

bool map[750][750];
int counts[750][750][4];
int dx[] = {-1, 1, 1, -1};
int dy[] = {-1, -1, 1, 1};

void solution() {
    int R, C, nx, ny;
    string s;

    cin >> R >> C;
    for (int y = 0; y < R; y++) {
        cin >> s;
        for (int x = 0; x < C; x++) {
            map[y][x] = (s[x] == '1');
        }
    }

    // 한 정점 기준 대각선 개수 세기
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (!map[y][x]) continue;

            for (int i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                counts[y][x][i] = 1;
                if (0 <= nx && nx < C && 0 <= ny && ny < R && map[ny][nx])
                    counts[y][x][i] += counts[ny][nx][i];
            }
        }
    }

    for (int y = R-1; y >= 0; y--) {
        for (int x = C-1; x >= 0; x--) {
            if (!map[y][x]) continue;

            for (int i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                counts[y][x][i] = 1;
                if (0 <= nx && nx < C && 0 <= ny && ny < R && map[ny][nx])
                    counts[y][x][i] += counts[ny][nx][i];
            }
        }
    }

    // 모든 1에 대해 다이아몬드 최댓값 구하기
    int maxNum = 0, maxK;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (!map[y][x]) continue;

            maxK = min(counts[y][x][2], counts[y][x][3]);
            for (int k = maxK; k > maxNum; k--) {
                nx = x;
                ny = y + 2*(k-1);
                if (ny < R && k <= min(counts[ny][nx][0], counts[ny][nx][1]))
                    maxNum = k;
            }
        }
    }
    cout << maxNum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}