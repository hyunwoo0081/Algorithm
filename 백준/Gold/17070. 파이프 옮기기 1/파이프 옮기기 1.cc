#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define HOR 0
#define VER 1
#define DIA 2

using namespace std;

int dp[3][16][16] = {0};
int map[16][16];

int getDp(int dir, int y, int x) {
    return 0 <= x && 0 <= y ? dp[dir][y][x] : 0;
}

void solution() {
    int N;

    cin >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> map[y][x];
        }
    }

    dp[HOR][0][1] = 1;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (map[y][x]) continue;
            dp[HOR][y][x] += getDp(HOR, y, x-1) + getDp(DIA, y, x-1);
            dp[VER][y][x] += getDp(VER, y-1, x) + getDp(DIA, y-1, x);
            if (0 < x && 0 < y && !map[y-1][x] && !map[y][x-1])
                dp[DIA][y][x] += getDp(HOR, y-1, x-1) + getDp(VER, y-1, x-1) + getDp(DIA, y-1, x-1);
        }
    }
    cout << dp[HOR][N-1][N-1] + dp[VER][N-1][N-1] + dp[DIA][N-1][N-1];
}

int main() {
    fastIO();
    solution();

    return 0;
}