#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char map[50][50];
int maxCount[50][50] = {0};
bool visited[50][50] = {false};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int getMaxCount(int x, int y, int N, int M) {
    if (visited[y][x]) return -1;
    if (maxCount[y][x] >= 0) return maxCount[y][x];
    visited[y][x] = true;

    int nx, ny, maxCnt, cnt, mul;
    mul = map[y][x]-'0';
    maxCnt = 0;
    for (int i = 0; i < 4; ++i) {
        nx = x + dx[i]*mul;
        ny = y + dy[i]*mul;
        if (0 <= nx && nx < M && 0 <= ny && ny < N) {
            cnt = getMaxCount(nx, ny, N, M);
            if (cnt == -1)
                return maxCount[y][x] = -1;
            maxCnt = max(maxCnt, cnt);
        }
    }
    visited[y][x] = false;

    return maxCount[y][x] = maxCnt+1;
}

void solution() {
    int N, M;
    string s;

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        cin >> s;
        for (int x = 0; x < M; ++x) {
            map[y][x] = s[x];
            maxCount[y][x] = s[x] == 'H' ? 0 : -1;
        }
    }

    cout << getMaxCount(0, 0, N, M);
}

int main() {
    fastIO();
    solution();

    return 0;
}