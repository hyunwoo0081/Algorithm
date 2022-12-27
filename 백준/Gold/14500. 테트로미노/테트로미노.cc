#include <iostream>
#define SIZE 500

using namespace std;

int blocks[19][4][2] = {{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
                        {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
                        {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
                        {{1, 2}, {0, 0}, {0, 1}, {0, 2}},
                        {{0, 1}, {0, 0}, {1, 0}, {2, 0}},
                        {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
                        {{2, 0}, {0, 1}, {1, 1}, {2, 1}},
                        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
                        {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
                        {{1, 1}, {0, 0}, {1, 0}, {2, 0}},
                        {{1, 1}, {0, 0}, {0, 1}, {0, 2}},
                        {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
                        {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
                        {{1, 0}, {0, 1}, {1, 1}, {0, 2}},
                        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
                        {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
                        {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
                        {{1, 0}, {0, 0}, {0, 1}, {0, 2}},
                        {{2, 1}, {0, 0}, {1, 0}, {2, 0}}};

int map[SIZE][SIZE] = {0};

void solution() {
    int N, M, nx, ny, maxN, sum;

    cin >> N >> M;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            cin >> map[y][x];

    maxN = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            for (auto &block : blocks) {
                sum = 0;
                for (auto &pixel: block) {
                    nx = x + pixel[0];
                    ny = y + pixel[1];
                    if (nx >= M || ny >= N) {
                        sum = 0;
                        break;
                    }
                    sum += map[ny][nx];
                }
                maxN = max(maxN, sum);
            }
        }
    }
    cout << maxN;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}