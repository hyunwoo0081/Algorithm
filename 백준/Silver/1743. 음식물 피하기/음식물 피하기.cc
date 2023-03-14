#include <iostream>
#include <vector>

using namespace std;

bool map[100][100] = {false};
vector<int> sizes;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N, M;

int getCount(int x, int y) {
    int nx, ny, count = 1;

    map[y][x] = false;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N && map[ny][nx])
            count += getCount(nx, ny);
    }

    return count;
}

void solution() {
    int K, r, c;

    cin >> N >> M >> K;
    while (K--) {
        cin >> r >> c;
        map[r-1][c-1] = true;
    }

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (map[y][x])
                sizes.push_back(getCount(x, y));

    int maxCount = 0;
    for (auto v: sizes)
        maxCount = max(maxCount, v);
    cout << maxCount;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}