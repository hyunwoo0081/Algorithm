#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int dust[50][50];
int nextDust[50][50];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cleanerTopX = 0, cleanerTopY = -1;
int cleanerBottomX = 0, cleanerBottomY = -1;

void calculateNextDust(int R, int C) {
    int count, nx, ny;
    for (int y = 0; y < R; ++y)
        for (int x = 0; x < C; ++x)
            nextDust[y][x] = 0;

    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            if (dust[y][x] > 0) {
                count = 0;
                for (int i = 0; i < 4; ++i) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if (0 <= nx && nx < C && 0 <= ny && ny < R && dust[ny][nx] >= 0) {
                        count++;
                        nextDust[ny][nx] += dust[y][x]/5;
                    }
                }
                dust[y][x] -= (dust[y][x]/5) * count;
            }
        }
    }

    for (int y = 0; y < R; ++y)
        for (int x = 0; x < C; ++x)
            dust[y][x] += nextDust[y][x];
}

void calculateCleaner(int R, int C) {
    for (int y = cleanerTopY-1; y > 0; --y)
        dust[y][cleanerTopX] = dust[y-1][cleanerTopX];
    for (int x = 0; x <= C-2; ++x)
        dust[0][x] = dust[0][x+1];
    for (int y = 0; y <= cleanerTopY-1; ++y)
        dust[y][C-1] = dust[y+1][C-1];
    for (int x = C-1; x > 1; --x)
        dust[cleanerTopY][x] = dust[cleanerTopY][x-1];
    dust[cleanerTopY][cleanerTopX+1] = 0;

    for (int y = cleanerBottomY+2; y < R; ++y)
        dust[y-1][cleanerBottomX] = dust[y][cleanerBottomX];
    for (int x = 0; x <= C-2; ++x)
        dust[R-1][x] = dust[R-1][x+1];
    for (int y = R-1; y > cleanerBottomY; --y)
        dust[y][C-1] = dust[y-1][C-1];
    for (int x = C-1; x > 1; --x)
        dust[cleanerBottomY][x] = dust[cleanerBottomY][x-1];
    dust[cleanerBottomY][cleanerBottomX+1] = 0;
}

void solution() {
    int R, C, T;
    
    cin >> R >> C >> T;
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            cin >> dust[y][x];
            if (dust[y][x] == -1 && cleanerTopY == -1) {
                cleanerTopY = y;
                cleanerBottomY = y+1;
            }
        }
    }

    while (T--) {
        calculateNextDust(R, C);
        calculateCleaner(R, C);
    }

    int sum = 0;
    for (int y = 0; y < R; ++y) {
        for (int x = 0; x < C; ++x) {
            if (dust[y][x] > 0)
                sum += dust[y][x];
        }
    }
    cout << sum;
}

int main() {
    fastIO();
    solution();

    return 0;
}