#include <iostream>
#include <queue>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

typedef struct Position {
    int x, y;
} Pos;

typedef struct DfsData {
    Pos red, blue;
    int depth, prevDir;
} dData;

bool map[10][10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<dData> q;

bool samePos(Pos &a, Pos &b) {
    return a.x == b.x && a.y == b.y;
}

bool moveBall(Pos & ball, Pos & otherBall, Pos & hole, int dir) {
    while (map[ball.y][ball.x] != 0 && !samePos(ball, otherBall) && !samePos(ball, hole)) {
        ball.x += dx[dir];
        ball.y += dy[dir];
    }
    if (samePos(ball, hole))
        return true;

    ball.x -= dx[dir];
    ball.y -= dy[dir];

    return false;
}

int findTrial(Pos sRed, Pos sBlue, Pos &hole) {
    q.push({sRed, sBlue, 0, -1});

    while (!q.empty()) {
        Pos red = sRed = q.front().red;
        Pos blue = sBlue = q.front().blue;
        int depth = q.front().depth;
        int prevDir = q.front().prevDir;
        q.pop();

        if (depth >= 10) continue;

        for (int i = 0; i < 4; ++i) {
            if (i == prevDir)
                continue;

            red = sRed;
            blue = sBlue;
            int flag = 0; //0: none, 1: red, 2:blue or both;
            if (moveBall(red, blue, hole, i))
                flag = 1;
            if (moveBall(blue, red, hole, i))
                flag = 2;
            if (moveBall(red, blue, hole, i))
                flag = max(flag, 1);

            if (flag == 1) return depth+1;
            if (flag == 2) continue;

            q.push({red, blue, depth+1, i});
        }
    }

    return -1;
}

void solution() {
    int N, M;
    Pos red, blue, hole;
    string inputs;

    cin >> N >> M;
    for (int y = 0; y < N; ++y) {
        cin >> inputs;
        for (int x = 0; x < M; ++x) {
            map[y][x] = inputs[x] != '#';

            if (inputs[x] == 'R')
                red.x = x, red.y = y;
            else if (inputs[x] == 'B')
                blue.x = x, blue.y = y;
            else if (inputs[x] == 'O')
                hole.x = x, hole.y = y;
        }
    }

    cout << findTrial(red, blue, hole);
}

int main() {
    fastIO();
    solution();

    return 0;
}