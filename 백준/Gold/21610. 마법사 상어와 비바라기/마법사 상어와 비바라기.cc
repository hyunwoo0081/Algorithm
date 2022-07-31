#include <iostream>

using namespace std;

long long map[50][50];
bool cloud[50][50] = {false};
bool movedCloud[50][50];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

void initCloud(int N) {
    cloud[N-1][0] = cloud[N-1][1] = true;
    cloud[N-2][0] = cloud[N-2][1] = true;
}

void moveCloud(int N, int d, int s) {
    int x, y, nx, ny;
    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            nx = (x + dx[d]*s + s*N) % N;
            ny = (y + dy[d]*s + s*N) % N;
            movedCloud[ny][nx] = cloud[y][x];
        }
    }
}

void rain(int N) {
    int x, y, nx, ny;
    int ddx[] = {-1, -1, 1, 1};
    int ddy[] = {-1, 1, -1, 1};

    for (y = 0; y < N; y++)
        for (x = 0; x < N; x++)
            if (movedCloud[y][x])
                map[y][x]++;

    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            if (movedCloud[y][x]) {
                for (int i = 0; i < 4; i++) {
                    nx = x + ddx[i];
                    ny = y + ddy[i];
                    if (0 <= nx && nx < N && 0 <= ny && ny < N && map[ny][nx] > 0)
                        map[y][x]++;
                }
            }
        }
    }
}

void createCloud(int N) {
    int x, y;
    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            cloud[y][x] = map[y][x] >= 2 && !movedCloud[y][x];
            if (cloud[y][x])
                map[y][x] -= 2;
        }
    }
}

long long getSum(int N) {
    long long sum = 0;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            sum += map[y][x];

    return sum;
}

void solution() {
    int N, M, x, y, d, s;
    cin >> N >> M;
    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }

    initCloud(N);
    while (M--) {
        cin >> d >> s;
        moveCloud(N, d-1, s);
        rain(N);
        createCloud(N);
    }

    cout << getSum(N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}