#include <iostream>
#include <vector>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int map[64][64];
vector<pair<int, int>> empty;
vector<pair<int, int>> virus;
queue<pair<int, int>> q;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int getSafeArea(int N, int M) {
    int count = empty.size()-3;
    int x, y;
    for (auto &v:virus) {
        q.push(v);

        while (!q.empty()) {
            for (int i = 0; i < 4; ++i) {
                x = q.front().first + dx[i];
                y = q.front().second + dy[i];
                if (0 <= x && x < M && 0 <= y && y < N && map[y][x] == 0) {
                    map[y][x] = 2;
                    q.push(make_pair(x, y));
                    count--;
                }
            }
            q.pop();
        }
    }

    for (auto &e:empty)
        map[e.second][e.first] = 0;

    return count;
}

void solution() {
    int N, M, max, tmp;

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> map[y][x];
            if (map[y][x] == 0)
                empty.push_back(make_pair(x, y));
            else if (map[y][x] == 2)
                virus.push_back(make_pair(x, y));
        }
    }

    max = -1;
    for (int i = 0; i < empty.size()-2; ++i) {
        for (int j = i+1; j < empty.size()-1; ++j) {
            for (int k = j+1; k < empty.size(); ++k) {
                map[empty[i].second][empty[i].first] = 1;
                map[empty[j].second][empty[j].first] = 1;
                map[empty[k].second][empty[k].first] = 1;

                tmp = getSafeArea(N, M);
                if (max == -1 || max < tmp)
                    max = tmp;
            }
        }
    }

    cout << max;
}

int main() {
    fastIO();
    solution();

    return 0;
}