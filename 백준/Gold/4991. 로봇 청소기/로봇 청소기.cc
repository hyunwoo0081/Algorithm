#include <iostream>
#include <unordered_map>
#include <queue>
#define INF 1000000000

using namespace std;

unordered_map<int, int> indexes;
vector<pair<int, int>> vertexes;
int edges[11][11];
char map[100][100];
int visited[100][100];
queue<pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool saveDist(int index, int W, int H) {
    int x, y, nx, ny, dist;
    while (!q.empty())
        q.pop();

    for (y = 0; y < H; ++y)
        for (x = 0; x < W; ++x)
            visited[y][x] = -1;

    int count = 0;
    x = vertexes[index].first;
    y = vertexes[index].second;
    q.emplace(x*100+y, 0);
    visited[y][x] = 0;
    map[y][x] = '.';
    while (!q.empty()) {
        x = q.front().first/100;
        y = q.front().first%100;
        dist = q.front().second;
        q.pop();

        if (visited[y][x] < dist) continue;

        for (int i = 0; i < 4; ++i) {
            nx = x+dx[i];
            ny = y+dy[i];
            if (0 <= nx && nx < W && 0 <= ny && ny < H && map[ny][nx] != 'x' && visited[ny][nx] == -1) {
                if (map[ny][nx] == '*') {
                    int target = indexes[nx*100+ny]-1;
                    edges[index][target] = dist+1;
                    edges[target][index] = dist+1;
                    if (++count >= vertexes.size()-index-1)
                        return true;
                }
                q.emplace(nx*100+ny, dist+1);
                visited[ny][nx] = dist+1;
            }
        }
    }

    return false;
}

bool makeEdges(int W, int H) {
    for (auto &es: edges)
        for (auto &edge: es)
            edge = INF;

    for (int i = 0; i < vertexes.size()-1; ++i) {
        if(!saveDist(i, W, H))
            return false;
    }
    return true;
}

int dfs(int index, int sum, int visit) {
    if (visit == (1 << vertexes.size())-1)
        return sum;

    int minDist = INF;
    for (int i = 1; i < vertexes.size(); ++i) {
        if (!(visit & (1<<i))) {
            minDist = min(minDist, dfs(i, sum+edges[index][i], visit|(1<<i)));
        }
    }

    return minDist;
}

void solution() {
    int W, H;
    string s;

    cin >> W >> H;
    while (W > 0 && H > 0) {
        indexes.clear();
        vertexes.clear();

        vertexes.emplace_back(-1, -1);
        for (int y = 0; y < H; ++y) {
            cin >> s;
            for (int x = 0; x < W; ++x) {
                map[y][x] = s[x];
                if (s[x] == '*') {
                    vertexes.emplace_back(x, y);
                    indexes[x*100+y] = vertexes.size();
                }
                else if (s[x] == 'o') {
                    vertexes[0] = make_pair(x, y);
                    indexes[x*100+y] = 1;
                }
            }
        }

        if (makeEdges(W, H))
            cout << dfs(0, 0, 1) << '\n';
        else
            cout << -1 << '\n';

        cin >> W >> H;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}