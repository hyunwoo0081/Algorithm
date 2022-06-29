#include <iostream>
#include <queue>

using namespace std;

int dist[250000] = {0};
int prevNode[250000] = {0};
int map[500][500][3];
queue<pair<int, int>> q;
vector<int> stack;

void addNextNode(int x, int y, int nx, int ny, int idx, int N) {
    if (0 <= nx && nx < N-ny%2 && 0 <= ny && ny < N
            && !dist[map[ny][nx][2]] && map[y][x][idx] == map[ny][nx][!idx]) {
        int node = map[y][x][2];
        int next = map[ny][nx][2];

        prevNode[next] = node;
        dist[next] = dist[node] + 1;
        q.emplace(nx, ny);
    }
}

void solution() {
    int N, x, y, count;

    count = 0;
    cin >> N;
    for (y = 0; y < N; ++y) {
        for (x = 0; x < N-y%2; ++x) {
            ++count;
            cin >> map[y][x][0] >> map[y][x][1];
            map[y][x][2] = count;
        }
    }

    //find path
    q.emplace(0, 0);
    dist[1] = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        addNextNode(x, y, x-1+y%2, y-1, 0, N);
        addNextNode(x, y, x-1, y, 0, N);
        addNextNode(x, y, x-1+y%2, y+1, 0, N);

        addNextNode(x, y, x+y%2, y-1, 1, N);
        addNextNode(x, y, x+1, y, 1, N);
        addNextNode(x, y, x+y%2, y+1, 1, N);
    }

    int idx = 1;
    for (int i = count; i > 0; --i) {
        if (dist[i] > 0) {
            idx = i;
            break;
        }
    }

    while (idx > 0) {
        stack.push_back(idx);
        idx = prevNode[idx];
    }
    cout << stack.size() << '\n';
    for (int i = stack.size()-1; i >= 0; --i) {
        cout << stack[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}