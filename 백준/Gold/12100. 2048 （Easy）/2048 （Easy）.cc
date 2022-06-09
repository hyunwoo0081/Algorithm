#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void nextMap(const int map[20][20], int target[20][20], int N, int dir) {
    if (dir == 0) {
        for (int y = 0; y < N; ++y) {
            int i = 0;
            for (int j = 0; j < N; ++j) {
                target[y][j] = 0;
                if (map[y][j] > 0) {
                    if (target[y][i] == map[y][j])
                        target[y][i++] = map[y][j]*2;
                    else if (target[y][i] == 0)
                        target[y][i] = map[y][j];
                    else
                        target[y][++i] = map[y][j];
                }
            }
        }
    }
    else if (dir == 1) {
        for (int x = 0; x < N; ++x) {
            int i = 0;
            for (int j = 0; j < N; ++j) {
                target[j][x] = 0;
                if (map[j][x] > 0) {
                    if (target[i][x] == map[j][x])
                        target[i++][x] = map[j][x]*2;
                    else if (target[i][x] == 0)
                        target[i][x] = map[j][x];
                    else
                        target[++i][x] = map[j][x];
                }
            }
        }
    }
    else if (dir == 2) {
        for (int y = 0; y < N; ++y) {
            int i = N-1;
            for (int j = N-1; j >= 0; --j) {
                target[y][j] = 0;
                if (map[y][j] > 0) {
                    if (target[y][i] == map[y][j])
                        target[y][i--] = map[y][j]*2;
                    else if (target[y][i] == 0)
                        target[y][i] = map[y][j];
                    else
                        target[y][--i] = map[y][j];
                }
            }
        }
    }
    else if (dir == 3) {
        for (int x = 0; x < N; ++x) {
            int i = N-1;
            for (int j = N-1; j >= 0; --j) {
                target[j][x] = 0;
                if (map[j][x] > 0) {
                    if (target[i][x] == map[j][x])
                        target[i--][x] = map[j][x]*2;
                    else if (target[i][x] == 0)
                        target[i][x] = map[j][x];
                    else
                        target[--i][x] = map[j][x];
                }
            }
        }
    }
}

int getMax(int map[20][20], int N, int depth) {
    int target[20][20];
    int maxNum = 0;

    if (depth <= 0) {
        for (int y = 0; y < N; ++y)
            for (int x = 0; x < N; ++x)
                maxNum = max(maxNum, map[y][x]);
        return maxNum;
    }

    for (int i = 0; i < 4; ++i) {
        nextMap(map, target, N, i);
        maxNum = max(maxNum, getMax(target, N, depth-1));
    }

    return maxNum;
}

void solution() {
    int map[20][20];
    int N;

    cin >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> map[y][x];
        }
    }
    cout << getMax(map, N, 5);
}

int main() {
    fastIO();
    solution();

    return 0;
}