#include <iostream>

using namespace std;

void bishop(bool target[10][10], bool map[10][10], int N, int bx, int by) {
    int f;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            target[y][x] = map[y][x];

    for (int x = 0; x < N; x++) {
        f = x - bx + by;
        if (0 <= f && f < N)
            target[f][x] = false;

        f = -x + bx + by;
        if (0 <= f && f < N)
            target[f][x] = false;
    }
}

int getCount(bool map[10][10], int N, int type, int depth, int count) {
    bool nMap[10][10];
    int nx, ny, result;

    result = count;
    for(; depth < N*N; depth++) {
        nx = depth%N;
        ny = depth/N;
        if ((nx+ny) % 2 == type && map[ny][nx]) {
            bishop(nMap, map, N, nx, ny);
            result = max(result, getCount(nMap, N, type, depth+1, count+1));
        }
    }

    return result;
}

void solution() {
    bool map[10][10];
    int N, a;

    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> a;
            map[y][x] = (bool) a;
        }
    }

    cout << getCount(map, N, 0, 0, 0) + getCount(map, N, 1, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}