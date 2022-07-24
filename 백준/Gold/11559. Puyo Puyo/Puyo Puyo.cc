#include <iostream>

using namespace std;

char map[12][6];
bool visited[12][6];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int isPossible(int x, int y) {
    int nx, ny, count = 0;

    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        nx = x+dx[i];
        ny = y+dy[i];
        if (0 <= nx && nx < 6 && 0 <= ny && ny < 12
                && map[ny][nx] == map[y][x] && !visited[ny][nx]) {
            count += isPossible(nx, ny);
        }
    }

    return count + 1;
}

void deletePuyo(int x, int y, char c) {
    map[y][x] = '.';

    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x+dx[i];
        ny = y+dy[i];
        if (0 <= nx && nx < 6 && 0 <= ny && ny < 12 && map[ny][nx] == c) {
            deletePuyo(nx, ny, c);
        }
    }
}

bool boom() {
    for (auto &vi : visited)
        for (auto &v : vi)
            v = false;

    bool flag = false;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (map[i][j] != '.' && !visited[i][j] && isPossible(j, i) >= 4) {
                deletePuyo(j, i, map[i][j]);
                flag = true;
            }
        }
    }

    return flag;
}

void updatePuyo() {
    char tmp;
    for (int j = 0; j < 6; j++) {
        int k = 11;
        for (int i = 11; i >= 0; i--) {
            if (map[i][j] != '.') {
                tmp = map[i][j];
                map[i][j] = '.';
                map[k][j] = tmp;
                k--;
            }
        }
    }
}

void solution() {
    string s;
    for (int i = 0; i < 12; i++) {
        cin >> s;
        for (int j = 0; j < 6; j++)
            map[i][j] = s[j];
    }

    int count = 0;
    while (boom()) {
        updatePuyo();
        count++;
    }

    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}