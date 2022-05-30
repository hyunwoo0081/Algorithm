#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INF 1000000000

using namespace std;

int floyd[100][100];
int path[100][100];
vector<int> pathVec;

void getPath(int start, int end) {
    if (pathVec.empty() || pathVec.back() != start)
        pathVec.push_back(start);

    if (path[start][end] == end) {
        pathVec.push_back(end);
        return;
    }

    getPath(start, path[start][end]);
    getPath(path[start][end], end);
}

void solution() {
    int N, M, a, b, c;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            floyd[i][j] = INF;
            path[i][j] = j;
        }
        floyd[i][i] = 0;
    }
    while (M--) {
        cin >> a >> b >> c;
        a--, b--;
        floyd[a][b] = min(floyd[a][b], c);
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (floyd[i][j] > floyd[i][k]+floyd[k][j]) {
                    floyd[i][j] = floyd[i][k]+floyd[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (floyd[i][j] == INF)
                floyd[i][j] = 0;
            cout << floyd[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (floyd[i][j] == 0)
                cout << '0';
            else {
                pathVec.clear();
                getPath(i, j);
                cout << pathVec.size() << ' ';
                for (auto p :pathVec)
                    cout << p+1 << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}