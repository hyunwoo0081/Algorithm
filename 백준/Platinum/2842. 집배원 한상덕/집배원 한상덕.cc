#include <iostream>
#include <algorithm>

using namespace std;

int map[50][50];
bool house[50][50];
bool visited[50][50];

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};

int values[50*50];
int valueSize = 0;

void visit(int x, int y, int N, int minV, int maxV) {
    int nx, ny;
    visited[y][x] = true;
    for (int i = 0; i < 8; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[ny][nx]
            && minV <= map[ny][nx] && map[ny][nx] <= maxV)
            visit(nx, ny, N, minV, maxV);
    }
}

bool canVisit(int px, int py, int N, int minV, int maxV) {
    if (map[py][px] < minV || maxV < map[py][px])
        return false;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            visited[y][x] = false;

    visit(px, py, N, minV, maxV);

    bool can = true;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            can &= !house[y][x] || visited[y][x];

    return can;
}

void solution() {
    int N, left, right, minAbs, px, py;
    string s;

    cin >> N;
    for (int y = 0; y < N; y++) {
        cin >> s;
        for (int x = 0; x < N; x++) {
            house[y][x] = s[x] != '.';
            if (s[x] == 'P')
                px = x, py = y;
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            values[valueSize++] = map[y][x];
        }
    }

    sort(values, values + valueSize);
    valueSize = 1;
    for (int i = 1; i < N*N; i++)
        if (values[i] != values[valueSize-1])
            values[valueSize++] = values[i];

    left = right = 0;
    minAbs = 987654321;
    while (left <= right && right < valueSize) {
        if (canVisit(px, py, N, values[left], values[right])) {
            minAbs = min(minAbs, values[right] - values[left]);
            left++;
        }
        else
            right++;
    }

    cout << minAbs;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}