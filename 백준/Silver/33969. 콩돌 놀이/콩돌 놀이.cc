#include <iostream>
#define SIZE 10

using namespace std;

char maps[SIZE][SIZE];
int shapeS[2][5][5] = {
    {
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0}
    },
    {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }
};
int shapeC[4][5][5] = {
    {
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0}
    },
    {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    },
    {
        {1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0}
    },
    {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }
};

void printMaps(int X, int Y) {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            cout << maps[y][x];
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isEmpty(int X, int Y) {
    bool empty = true;

    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
            empty &= (maps[y][x] == '.');

    return empty;
}

bool replace(int x, int y, int X, int Y, int shape[5][5], char from, char to) {
    // Check if replacement is possible
    for (int dx = 0; dx < 5; dx++) {
        for (int dy = 0; dy < 5; dy++) {
            if (shape[dy][dx] == 0)
                continue;

            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= X || ny < 0 || ny >= Y)
                return false;

            if (maps[ny][nx] != from)
                return false;
        }
    }

    // Perform replacement
    for (int dx = 0; dx < 5; dx++) {
        for (int dy = 0; dy < 5; dy++) {
            if (shape[dy][dx] == 1) {
                int nx = x + dx;
                int ny = y + dy;
                maps[ny][nx] = to;
            }
        }
    }

    return true;
}

bool search(int pos, int X, int Y, int s, int c) {
    bool hasResult = false;

    // Skip empty cells
    while (pos < X * Y && maps[pos / X][pos % X] == '.')
        pos++;

    // cout << "pos: " << pos << "\n";
    // printMaps(X, Y);

    // Base Case
    if (pos == X * Y) {
        if (!isEmpty(X, Y))
            return false;

        cout << s << " " << c << "\n";
        return true;
    }


    // Recursive Case
    int x = pos % X;
    int y = pos / X;
    for (auto &shape : shapeS) {
        if (replace(x, y, X, Y, shape, 'x', '.')) {
            hasResult |= search(pos+1, X, Y, s + 1, c);
            replace(x, y, X, Y, shape, '.', 'x');

            if (hasResult) return true;
        }
    }

    for (auto &shape : shapeC) {
        if (replace(x, y, X, Y, shape, 'x', '.')) {
            hasResult |= search(pos+1, X, Y, s, c + 1);
            replace(x, y, X, Y, shape, '.', 'x');

            if (hasResult) return true;
        }
    }

    return false;
}

void solution() {
    int N, M;
    string s;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++)
            maps[i][j] = s[j];
    }

    if (!search(0, M, N, 0, 0)) {
        cout << -1 << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}
