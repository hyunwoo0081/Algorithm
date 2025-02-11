#include <iostream>
#include <deque>
#define SIZE 1000
#define NOT_VISITED (-1)

using namespace std;

deque<pair<int, int>> q;
bool maps[SIZE][SIZE];
int visited[SIZE][SIZE];
int maxValue;

int dxs[] = {0, 0, -1, 1};
int dys[] = {-1, 1, 0, 0};

void solution() {
    int T, x, y, X, Y, a;

    cin >> T;
    while (T--) {
        cin >> Y >> X;
        maxValue = 0;
        for (y = 0; y < Y; y++) {
            for (x = 0; x < X; x++) {
                cin >> a;
                maps[y][x] = a == 1;
                visited[y][x] = NOT_VISITED;

                if (y == 0 || y == Y - 1 || x == 0 || x == X - 1) {
                    if (maps[y][x]) {
                        q.emplace_back(x, y);
                        visited[y][x] = 1;
                    }
                    else {
                        q.emplace_front(x, y);
                        visited[y][x] = 0;
                    }
                }
            }
        }

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop_front();

            for (int i = 0; i < 4; i++) {
                int nx = x + dxs[i];
                int ny = y + dys[i];

                if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
                if (visited[ny][nx] != NOT_VISITED) continue;

                visited[ny][nx] = visited[y][x] + maps[ny][nx];
                maxValue = max(maxValue, visited[ny][nx]);
                if (maps[ny][nx])
                    q.emplace_back(nx, ny);
                else
                    q.emplace_front(nx, ny);
            }
        }

        int result = 0;
        while (result == 0) {
            result = 0;
            for (y = 0; y < Y; y++) {
                for (x = 0; x < X; x++) {
                    result += visited[y][x] == maxValue && !maps[y][x];
                }
            }

            if (result == 0) maxValue--;
        }


        cout << maxValue << ' ' << result << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}