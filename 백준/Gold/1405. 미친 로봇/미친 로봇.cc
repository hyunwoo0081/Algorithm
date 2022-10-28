#include <iostream>
#include <iomanip>

using namespace std;

bool map[31][31] = {false};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int proba[4];

double getProba(int x, int y, int depth) {
    int nx, ny, p;
    double sum = 0;

    if (depth == 0)
        return 1.0;

    map[y][x] = true;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (!map[ny][nx]) {
            map[ny][nx] = true;
            sum += proba[i] * getProba(nx, ny, depth-1) / 100.0;
            map[ny][nx] = false;
        }
    }
    map[y][x] = false;

    return sum;
}

void solution() {
    int N;
    cin >> N;
    for (auto &p: proba)
        cin >> p;

    cout << setprecision(15);
    cout << getProba(15, 15, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
