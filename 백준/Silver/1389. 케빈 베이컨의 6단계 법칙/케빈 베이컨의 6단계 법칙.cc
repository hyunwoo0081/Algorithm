#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define INF 100000

using namespace std;

int floyd[100][100] = {0};

void solution() {
    int N, M, A, B;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            floyd[i][j] = INF;
        floyd[i][i] = 0;
    }

    while (M--) {
        cin >> A >> B;
        A--, B--;
        floyd[A][B] = floyd[B][A] = 1;
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (floyd[i][j] > floyd[i][k]+floyd[k][j])
                    floyd[i][j] = floyd[j][i] = floyd[i][k]+floyd[k][j];
            }
        }
    }

    int k = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < N; ++j)
            floyd[i][0] += floyd[i][j];
        if (floyd[k][0] > floyd[i][0])
            k = i;
    }
    cout << k+1;
}

int main() {
    fastIO();
    solution();

    return 0;
}