#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool dist[100][100];

void solution() {
    int N, x;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> x;
            dist[i][j] = x == 1;
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] && dist[k][j])
                    dist[i][j] = true;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}