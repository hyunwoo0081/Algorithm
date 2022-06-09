#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int map[50][50];
int stack[6][3];
int stackSize = 0;

void rotate(int r, int c, int s) {
    if (s <= 0) return;
    rotate(r, c, s-1);

    int tmp = map[r-s][c-s];
    for (int i = r-s+1; i <= r+s; ++i)
        map[i-1][c-s] = map[i][c-s];
    for (int i = c-s+1; i <= c+s; ++i)
        map[r+s][i-1] = map[r+s][i];
    for (int i = r+s-1; i >= r-s; --i)
        map[i+1][c+s] = map[i][c+s];
    for (int i = c+s-1; i >= c-s+1; --i)
        map[r-s][i+1] = map[r-s][i];
    map[r-s][c-s+1] = tmp;
}

void rotateRev(int r, int c, int s) {
    if (s <= 0) return;
    rotateRev(r, c, s-1);

    int tmp = map[r-s][c-s];
    for (int i = c-s+1; i <= c+s; ++i)
        map[r-s][i-1] = map[r-s][i];
    for (int i = r-s+1; i <= r+s; ++i)
        map[i-1][c+s] = map[i][c+s];
    for (int i = c+s-1; i >= c-s; --i)
        map[r+s][i+1] = map[r+s][i];
    for (int i = r+s-1; i >= r-s+1; --i)
        map[i+1][c-s] = map[i][c-s];
    map[r-s+1][c-s] = tmp;
}

int getMin(int N, int M, int K, int visited) {
    int minSum = 10000;
    if (visited == (1<<K)-1) {
        for (int y = 0; y < N; ++y) {
            int sum = 0;
            for (int x = 0; x < M; ++x)
                sum += map[y][x];
            minSum = min(minSum, sum);
        }
        return minSum;
    }

    for (int i = 0; i < K; ++i) {
        if (!(visited & (1<<i))) {
            rotate(stack[i][0], stack[i][1], stack[i][2]);
            minSum = min(minSum, getMin(N, M, K, visited|(1<<i)));
            rotateRev(stack[i][0], stack[i][1], stack[i][2]);
        }
    }

    return minSum;
}

void solution() {
    int N, M, K;

    cin >> N >> M >> K;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> map[y][x];
        }
    }
    for (int i = 0; i < K; ++i) {
        cin >> stack[stackSize][0] >> stack[stackSize][1] >> stack[stackSize][2];
        stack[stackSize][0]--;
        stack[stackSize][1]--;
        stackSize++;
    }

    cout << getMin(N, M, K, 0);
}

int main() {
    fastIO();
    solution();

    return 0;
}