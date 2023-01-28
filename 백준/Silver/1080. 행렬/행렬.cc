#include <iostream>
#define SIZE 50

using namespace std;

bool inputs[SIZE][SIZE];
bool target[SIZE][SIZE];

void change(int x, int y) {
    int nx, ny;
    for (int dy = 0; dy < 3; dy++) {
        for (int dx = 0; dx < 3; dx++) {
            nx = x + dx;
            ny = y + dy;
            inputs[ny][nx] = !inputs[ny][nx];
        }
    }
}

void solution() {
    int N, M, count;
    string s;

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        cin >> s;
        for (int x = 0; x < M; x++)
            inputs[y][x] = s[x] == '0';
    }

    for (int y = 0; y < N; y++) {
        cin >> s;
        for (int x = 0; x < M; x++)
            target[y][x] = s[x] == '0';
    }

    count = 0;
    for (int y = 0; y < N-2; y++) {
        for (int x = 0; x < M-2; x++) {
            if (inputs[y][x] != target[y][x]) {
                change(x, y);
                count++;
            }
        }
    }

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (inputs[y][x] != target[y][x])
                count = -1;

    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}