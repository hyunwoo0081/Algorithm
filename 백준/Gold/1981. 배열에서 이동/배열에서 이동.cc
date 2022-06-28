#include <iostream>
#include <queue>

using namespace std;

int map[100][100];
bool visited[100][100];
queue<pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isPossible(int min, int max, int N) {
    if (map[0][0] < min || max < map[0][0])
        return false;

    int x, y, nx, ny;
    while (!q.empty()) q.pop();
    for (y = 0; y < N; ++y) {
        for (x = 0; x < N; ++x) {
            visited[y][x] = false;
        }
    }

    q.emplace(0, 0);
    visited[0][0] = true;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[ny][nx]
                    && min <= map[ny][nx] && map[ny][nx] <= max) {
                visited[ny][nx] = true;
                q.emplace(nx, ny);
                if (nx == N-1 && ny == N-1)
                    return true;
            }
        }
    }

    return false;
}

bool isPossibleInRange(int minN, int maxN, int range, int N) {
    for (int start = minN; start+range <= maxN; ++start) {
        if (isPossible(start, start+range, N))
            return true;
    }
    return false;
}

void solution() {
    int N, minN, maxN;

    cin >> N;
    minN = 200, maxN = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> map[y][x];
            minN = min(minN, map[y][x]);
            maxN = max(maxN, map[y][x]);
        }
    }

    int lo = 0, hi = maxN-minN, mid;
    while (lo < hi) {
        mid = (lo + hi)/2;
        if (isPossibleInRange(minN, maxN, mid, N)) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }

    cout << lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}