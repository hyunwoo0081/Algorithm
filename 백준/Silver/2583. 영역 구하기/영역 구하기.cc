#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[100][100] = {false};
vector<int> result;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int getAreaCount(int x, int y, int M, int N) {
    int count = 1, nx, ny;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[ny][nx])
            count += getAreaCount(nx, ny, M, N);
    }

    return count;
}

void solution() {
    int M, N, K, x1, y1, x2, y2;

    cin >> M >> N >> K;
    while (K--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++)
            for (int x = x1; x < x2; x++)
                visited[y][x] = true;
    }

    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            if (!visited[y][x])
                result.push_back(getAreaCount(x, y, M, N));

    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for (auto v: result)
        cout << v << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}