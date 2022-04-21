#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool airMask[100][100] = {false};
bool cheese[100][100];
bool fadedCheese[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int airCount = 0;
int N, M;

void updateAirMask(int x, int y) {
    if (cheese[y][x]) return;

    if (!airMask[y][x]) {
        airMask[y][x] = true;
        airCount--;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N && !airMask[ny][nx])
            updateAirMask(x+dx[i], y+dy[i]);
    }
}

void removeCheeses() {
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            fadedCheese[y][x] = false;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (cheese[y][x]) {
                int count = 0;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (0 <= nx && nx < M && 0 <= ny && ny < N && airMask[ny][nx])
                        count++;
                }

                if (count >= 2)
                    fadedCheese[y][x] = true;
            }
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (fadedCheese[y][x]) {
                cheese[y][x] = false;
                updateAirMask(x, y);
            }
        }
    }
}

void solution() {
    int che, time;

    cin >> N >> M;
    airCount = N*M;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> che;
            cheese[y][x] = che == 1;
        }
    }

    //init airMask
    for (int x = 0; x < M; ++x) {
        updateAirMask(x, 0);
        updateAirMask(x, N-1);
    }
    for (int y = 0; y < N; ++y) {
        updateAirMask(0, y);
        updateAirMask(M-1, y);
    }

    time = 0;
    while (airCount > 0) {
        removeCheeses();
        time++;
    }

    cout << time;
}

int main() {
    fastIO();
    solution();

    return 0;
}