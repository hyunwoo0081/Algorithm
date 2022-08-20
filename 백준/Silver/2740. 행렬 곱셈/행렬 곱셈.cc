#include <iostream>

using namespace std;

void solution() {
    int N, M, K;
    int A[100][100], B[100][100], C[100][100];

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    cin >> M >> K;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> B[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            C[i][j] = 0;
            for (int k = 0; k < M; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++)
            cout << C[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}