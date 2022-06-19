#include <iostream>

using namespace std;

char map[10][10];
int dp[10][10][5];

int getCount(string &str, int x, int y, int N, int M, int depth) {
    int nx, ny;
    if (depth >= str.length())
        return 1;
    if (dp[y][x][depth] >= 0)
        return dp[y][x][depth];

    dp[y][x][depth] = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;

            nx = (x+dx+M) % M;
            ny = (y+dy+N) % N;

            if (map[ny][nx] == str[depth])
                dp[y][x][depth] += getCount(str, nx, ny, N, M, depth+1);
        }
    }

    return dp[y][x][depth];
}

void solution() {
    int N, M, K;
    long long count;
    string str;

    cin >> N >> M >> K;
    for (int y = 0; y < N; ++y) {
        cin >> str;
        for (int x = 0; x < M; ++x) {
            map[y][x] = str[x];
        }
    }

    while (K--) {
        count = 0;

        cin >> str;
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                for (int i = 0; i < str.length(); ++i) {
                    dp[y][x][i] = -1;
                }
            }
        }

        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                if (map[y][x] != str[0])
                    continue;

                count += getCount(str, x, y, N, M, 1);
            }
        }

        cout << count << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}