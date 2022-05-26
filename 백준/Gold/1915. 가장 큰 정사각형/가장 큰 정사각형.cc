#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int map[1000][1000];

void solution() {
    int N, M, maxWidth;
    string s;

    cin >> N >> M;
    maxWidth = 0;
    for (int y = 0; y < N; ++y) {
        cin >> s;
        for (int x = 0; x < M; ++x) {
            map[y][x] = s[x]-'0';
            maxWidth = max(maxWidth, map[y][x]);
        }
    }

    for (int y = 1; y < N; ++y) {
        for (int x = 1; x < M; ++x) {
            if (map[y][x] == 1){
                map[y][x] = min(min(map[y-1][x], map[y][x-1]), map[y-1][x-1]) + 1;
                maxWidth = max(maxWidth, map[y][x]);
            }
        }
    }

    cout << maxWidth*maxWidth;
}

int main() {
    fastIO();
    solution();

    return 0;
}