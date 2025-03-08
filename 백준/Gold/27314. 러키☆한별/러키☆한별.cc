#include <iostream>
#include <vector>
#include <queue>
#define SIZE 100000

using namespace std;

char maps[SIZE];
int visited[101][SIZE] = {0};
vector<int> ps;
vector<int> sharps;
int h;

queue<int> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int move(int start, int dx, int dy, int N, int M) {
    int result = start + dx + dy * M;
    int x = start % M + dx;

    if (result < 0 || result >= N*M || x < 0 || x >= M)
        return -1;

    return result;
}

void bfs(int start, int *visited, int N, int M) {
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next = move(cur, dx[i], dy[i], N, M);
            if (next == -1 || maps[next] == 'X' || visited[next] != 0)
                continue;

            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
}


void solution() {
    int N, M;
    string s;

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        cin >> s;
        for (int x = 0; x < M; x++) {
            maps[y * M + x] = s[x];

            if (maps[y * M + x] == 'P') {
                ps.push_back(y * M + x);
            } else if (maps[y * M + x] == '#') {
                sharps.push_back(y * M + x);
            } else if (maps[y * M + x] == 'H') {
                h = y * M + x;
            }
        }
    }


    bfs(h, visited[0], N, M);
    for (int i = 0; i < ps.size(); i++) {
        bfs(ps[i], visited[i+1], N, M);
    }

    int result = 0;
    for (auto sharp : sharps) {
        int p = 0;
        for (int i = 0; i < ps.size(); i++) {
            p += visited[i+1][sharp] != 0 && visited[0][sharp] >= visited[i+1][sharp];
        }

        result = max(result, p);
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}