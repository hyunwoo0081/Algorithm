#include <iostream>
#define LIM 100

using namespace std;

bool visited[LIM][LIM] = {false};
void visit(int sx, int sy, int X, int Y) {
    int x, y;

    visited[sy][sx] = true;
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) {
            x = sx + dx;
            y = sy + dy;

            if (x < 0 || X <= x || y < 0 || Y <= y || visited[y][x]) continue;

            visit(x, y, X, Y);
        }
}

int getAreaCnt(int X, int Y) {
    int result = 0;
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            if (!visited[y][x]) {
                result++;
                visit(x, y, X, Y);
            }

    return result;
}

void solution() {
    int N, M;
    string s;

    cin >> M >> N;
    while (N || M) {
        for (int y = 0; y < M; y++) {
            cin >> s;
            for (int x = 0; x < N; x++)
                visited[y][x] = s[x] == '*';
        }

        cout << getAreaCnt(N, M) << '\n';
        cin >> M >> N;
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}