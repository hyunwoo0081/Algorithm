#include <iostream>
#define SIZE 100

using namespace std;

bool maps[SIZE][SIZE];
bool visited[2][SIZE][SIZE];

bool isFull(int t, int X, int Y) {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (maps[y][x] != visited[t][y][x]) return false;
        }
    }
    return true;
}

void solution() {
    int X, Y, Mx, My, result = 0, prevT, currT, nx, ny;
    string s;
    char c;

    cin >> X >> Y >> Mx >> My;
    Mx--, My--;
    for (int y = 0; y < Y; y++) {
        cin >> s;
        for (int x = 0; x < X; x++)
            maps[y][x] = s[x] == '.';
    }

    visited[0][Y-My-1][Mx] = true;
    while (!isFull(result%2, X, Y)) {
        prevT = result % 2;
        currT = (result+1) % 2;
        result++;

        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                if (!maps[y][x]) continue;

                if (visited[prevT][y][x]) {
                    visited[currT][y][x] = true;
                    continue;
                }

                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        nx = x + dx;
                        ny = y + dy;

                        if (0 <= nx && nx < X && 0 <= ny && ny < Y && maps[ny][nx] && visited[prevT][ny][nx]) {
                            visited[currT][y][x] = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << result << '\n';
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}