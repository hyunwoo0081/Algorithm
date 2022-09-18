#include <iostream>
#include <queue>

using namespace std;

int map[50][50];
int visited[50][50];
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int availableInfect = -1;
int getCanInfectCount(int N) {
    if (availableInfect >= 0)
        return availableInfect;

    availableInfect = 0;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (map[y][x] == 0)
                availableInfect++;
    return availableInfect;
}

int getInfectionTime(int N, int infected) {
    int x, y, nx, ny, available;

    for (y = 0; y < N; y++)
        for (x = 0; x < N; x++)
            visited[y][x] = 0;
    while (!q.empty())
        q.pop();

    available = getCanInfectCount(N);
    if (available == 0) return 0;

    for (int i = 0; i < virus.size(); i++) {
        if (infected & (1<<i)) {
            x = virus[i].first;
            y = virus[i].second;
            q.emplace(x, y);      //init position
            visited[y][x] = 1;
        }
    }
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N
                && map[ny][nx] != 1 && !visited[ny][nx]) {
                if (map[ny][nx] == 0 && (--available) == 0)
                    return visited[y][x];

                q.emplace(nx, ny);
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }

    return -1;
}

int getMinTime(int N, int M, int infected, int pointer) {
    int time, minTime = -1;
    if (M == 0) {
        time = getInfectionTime(N, infected);
        return time;
    }

    for (; pointer < virus.size(); pointer++) {
        time = getMinTime(N, M-1, infected|(1<<pointer), pointer+1);
        if (minTime == -1 || 0 <= time && time < minTime)
            minTime = time;
    }
    return minTime;
}

void solution() {
    int N, M;

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            if (map[y][x] == 2)
                virus.emplace_back(x, y);
        }
    }

    cout << getMinTime(N, M, 0, 0);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}