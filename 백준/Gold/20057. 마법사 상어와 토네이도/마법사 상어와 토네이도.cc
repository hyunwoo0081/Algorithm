#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int map[499][499];
int tornado[5][5] = {
        {0,  0, 2, 0, 0},
        {0, 10, 7, 1, 0},
        {5,  0, 0, 0, 0},
        {0, 10, 7, 1, 0},
        {0,  0, 2, 0, 0}};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int count = 2, moved = 0, dir = 0;
bool nextPosition(int &x, int &y) {
    if (moved >= count/2) {
        count++;
        moved = 0;
        dir = (dir+1) % 4;
    }
    x += dx[dir];
    y += dy[dir];
    moved++;

    return x >= 0 && y >= 0;
}

int calculateTornado(int x, int y, int N) {
    int centerSend = map[y][x];
    int removedSend = 0;
    int outerSend = 0;
    int nx, ny;

    if (dir == 0) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                nx = x + (j-2);
                ny = y + (i-2);
                if (0 <= nx && nx < N && 0 <= ny && ny < N)
                    map[ny][nx] += centerSend * tornado[i][j]/100;
                else
                    outerSend += centerSend * tornado[i][j]/100;
                removedSend += centerSend * tornado[i][j]/100;
            }
        }
    }
    else if (dir == 1) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                nx = x + (j-2);
                ny = y + (i-2);
                if (0 <= nx && nx < N && 0 <= ny && ny < N)
                    map[ny][nx] += centerSend * tornado[j][4-i]/100;
                else
                    outerSend += centerSend * tornado[j][4-i]/100;
                removedSend += centerSend * tornado[j][4-i]/100;
            }
        }
    }
    else if (dir == 2) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                nx = x + (j-2);
                ny = y + (i-2);
                if (0 <= nx && nx < N && 0 <= ny && ny < N)
                    map[ny][nx] += centerSend * tornado[i][4-j]/100;
                else
                    outerSend += centerSend * tornado[i][4-j]/100;
                removedSend += centerSend * tornado[i][4-j]/100;
            }
        }
    }
    else {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                nx = x + (j-2);
                ny = y + (i-2);
                if (0 <= nx && nx < N && 0 <= ny && ny < N)
                    map[ny][nx] += centerSend * tornado[j][i]/100;
                else
                    outerSend += centerSend * tornado[j][i]/100;
                removedSend += centerSend * tornado[j][i]/100;
            }
        }
    }

    nx = x + dx[dir];
    ny = y + dy[dir];
    if (0 <= nx && nx < N && 0 <= ny && ny < N)
        map[ny][nx] += centerSend - removedSend;
    else
        outerSend += centerSend - removedSend;
    map[y][x] = 0;

    return outerSend;
}

void solution() {
    int N, x, y, sum;

    cin >> N;
    for (y = 0; y < N; ++y)
        for (x = 0; x < N; ++x)
            cin >> map[y][x];

    sum = 0;
    x = y = N/2;
    while (nextPosition(x, y)) {
        sum += calculateTornado(x, y, N);
    }
    cout << sum;
}

int main() {
    fastIO();
    solution();

    return 0;
}