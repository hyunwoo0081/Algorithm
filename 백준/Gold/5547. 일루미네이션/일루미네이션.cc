#include <iostream>
#define SIZE 102

using namespace std;

bool maps[SIZE][SIZE] = {false};
bool outArea[SIZE][SIZE] = {false};
bool visited[SIZE][SIZE] = {false};

void dfs(int x, int y, int W, int H) {
    if (x < 0 || x > W+1 || y < 0 || y > H+1)
        return;
    if (visited[y][x]) return;
    if (maps[y][x]) return;

    visited[y][x] = outArea[y][x] = true;
    dfs(x-1, y, W, H);
    dfs(x+1, y, W, H);

    int dx = y % 2 == 0 ? -1 : 1;
    dfs(x+dx, y-1, W, H);
    dfs(x+dx, y+1, W, H);
    dfs(x, y-1, W, H);
    dfs(x, y+1, W, H);
}

void solution() {
    int W, H, x, y, a, dx;

    cin >> W >> H;
    for (y = 1; y <= H; y++) {
        for (x = 1; x <= W; x++) {
            cin >> a;
            maps[y][x] = a == 1;
        }
    }

    dfs(0, 0, W, H);

    // for (y = 1; y <= H; y++) {
    //     for (x = 1; x <= W; x++) {
    //         cout << outArea[y][x] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int result = 0;
    for (y = 1; y <= H; y++) {
        for (x = 1; x <= W; x++) {
            if (outArea[y][x]) continue;

            result += outArea[y][x-1];
            result += outArea[y][x+1];

            dx = y % 2 == 0 ? -1 : 1;
            result += outArea[y-1][x+dx];
            result += outArea[y+1][x+dx];
            result += outArea[y-1][x];
            result += outArea[y+1][x];
        }
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}