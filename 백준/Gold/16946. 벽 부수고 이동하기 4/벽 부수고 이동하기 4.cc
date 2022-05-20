#include <iostream>
#include <vector>
#include <algorithm>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define WALL -1
#define EMPTY -2

using namespace std;

int map[1000][1000];
vector<int> counts;
vector<int> indexes;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int setArea(int x, int y, int N, int M) {
    int nx, ny, count = 1;
    map[y][x] = counts.size();

    for (int i = 0; i < 4; ++i) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N && map[ny][nx] == EMPTY)
            count += setArea(nx, ny, N, M);
    }

    return count;
}

void solution() {
    int N, M, nx, ny;
    string s;
    
    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        cin >> s;
        for (int x = 0; x < M; ++x) {
            map[y][x] = (s[x] == '1') - 2;
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (map[y][x] == EMPTY)
                counts.push_back(setArea(x, y, N, M));
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (map[y][x] != WALL) {
                cout << 0;
            }
            else {
                indexes.clear();
                int count = 1;
                for (int i = 0; i < 4; ++i) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if (0 <= nx && nx < M && 0 <= ny && ny < N && map[ny][nx] != WALL) {
                        auto il = find(indexes.begin(), indexes.end(), map[ny][nx]);
                        if (il == indexes.end()) {
                            count += counts[map[ny][nx]];
                            indexes.push_back(map[ny][nx]);
                        }
                    }
                }
                cout << count%10;
            }
        }
        cout << '\n';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}