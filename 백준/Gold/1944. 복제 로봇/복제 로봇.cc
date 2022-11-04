#include <iostream>
#include <queue>
#define SIZE 50
#define K_SIZE 251

using namespace std;

bool map[SIZE][SIZE];
int visited[SIZE][SIZE];
int unions[K_SIZE];
vector<pair<int, int>> vertices;
priority_queue<pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


void makeDistMap(pair<int, int> &vertex, int N) {
    int x, y, nx, ny;
    queue<pair<int, int>> path;

    for (y = 0; y < N; y++)
        for (x = 0; x < N; x++)
            visited[y][x] = -1;

    visited[vertex.second][vertex.first] = 0;
    path.emplace(vertex.first, vertex.second);
    while (!path.empty()) {
        x = path.front().first;
        y = path.front().second;
        path.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N
                && map[ny][nx] && visited[ny][nx] < 0) {
                visited[ny][nx] = visited[y][x] + 1;
                path.emplace(nx, ny);
            }
        }
    }
}

int findRoot(int x) {
    while (unions[x] >= 0)
        x = unions[x];
    return x;
}

bool joinUnion(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a == b)
        return false;

    if (unions[a] > unions[b]) {
        unions[a] = b;
    }
    else {
        unions[a] = min(unions[b]-1, unions[a]);
        unions[b] = a;
    }

    return true;
}

int getMinLength(int N, int M) {
    int x, y, d, sum, count;

    for (int i = 0; i <= M; i++)
        unions[i] = -1;
    while (!q.empty())
        q.pop();

    // make edges and push q
    for (int i = 0; i <= M; i++) {
        makeDistMap(vertices[i], N);

        for (int j = i+1; j <= M; j++) {
            x = vertices[j].first;
            y = vertices[j].second;
            if (visited[y][x] != -1)
                q.emplace(-visited[y][x], i*K_SIZE + j);
        }
    }

    sum = 0;
    count = M;
    while (count && !q.empty()) {
        x = q.top().second / K_SIZE;
        y = q.top().second % K_SIZE;
        d = -q.top().first;
        q.pop();

        if (joinUnion(x, y)) {
            sum += d;
            count--;
        }
    }

    return count == 0 ? sum : -1;
}

void solution() {
    int N, M;
    string s;

    vertices.reserve(K_SIZE);

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        cin >> s;
        for (int x = 0; x < N; x++) {
            map[y][x] = s[x] != '1';
            if (s[x] == 'K' || s[x] == 'S')
                vertices.emplace_back(x, y);
        }
    }

    cout << getMinLength(N, M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
