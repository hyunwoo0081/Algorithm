#include <iostream>
#define PATH_SIZE 51
#define SIZE 100

using namespace std;

int path[PATH_SIZE];
bool originalShape[PATH_SIZE][PATH_SIZE];
bool shape[PATH_SIZE][PATH_SIZE];
int pathStack[SIZE][PATH_SIZE];
int pathStackSize = 0;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isSame() {
    for (int y = 0; y < PATH_SIZE; y++)
        for (int x = 0; x < PATH_SIZE; x++)
            if (originalShape[y][x] != shape[y][x])
                return false;
    return true;
}

void initialShape(bool shapeMap[PATH_SIZE][PATH_SIZE]) {
    for (int y = 0; y < PATH_SIZE; y++)
        for (int x = 0; x < PATH_SIZE; x++)
            shapeMap[y][x] = false;
}

void makeShape(bool shape[PATH_SIZE][PATH_SIZE], const int path[PATH_SIZE], int N) {
    int sx, sy, x, y, p;
    initialShape(shape);

    // calc start point
    sx = sy = x = y = 0;
    for (int i = 0; i < N; i++) {
        p = path[i]-1;

        x += dx[p];
        y += dy[p];
        sx = min(sx, x);
        sy = min(sy, y);
    }
    sx = -sx;
    sy = -sy;

    // make shape
    x = sx;
    y = sy;
    shape[y][x] = true;
    for (int i = 0; i < N; i++) {
        p = path[i]-1;

        x += dx[p];
        y += dy[p];
        shape[y][x] = true;
    }
}

void solution() {
    int N, L;

    cin >> L;
    for (int x = 0; x < L; x++)
        cin >> path[x];
    makeShape(originalShape, path, L);

    cin >> N;
    while (N--) {
        for (int x = 0; x < L; x++)
            cin >> path[x];

        makeShape(shape, path, L);
        if (isSame()) {
            for (int y = 0; y < L; y++)
                pathStack[pathStackSize][y] = path[y];
            pathStackSize++;
        }
    }

    cout << pathStackSize << '\n';
    for (int x = 0; x < pathStackSize; x++) {
        for (int y = 0; y < L; y++)
            cout << pathStack[x][y] << ' ';
        cout << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}